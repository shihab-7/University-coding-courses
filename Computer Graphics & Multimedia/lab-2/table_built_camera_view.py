import ctypes
import glfw
from OpenGL.GL import *
import numpy as np
import math

class Camera:
    def __init__(self, position=None, yaw=-90.0, pitch=0.0):
        self.position = np.array(position if position else [0.0, 1.0, 4.0], dtype=np.float32)
        self.front = np.array([0.0, 0.0, -1.0], dtype=np.float32)
        self.up = np.array([0.0, 1.0, 0.0], dtype=np.float32)
        self.right = np.array([1.0, 0.0, 0.0], dtype=np.float32)
        self.world_up = np.array([0.0, 1.0, 0.0], dtype=np.float32)
        self.yaw = yaw
        self.pitch = pitch
        self.mouse_sensitivity = 0.1
        self.update_camera_vectors()

    def get_view_matrix(self):
        return look_at(self.position, self.position + self.front, self.up)

    def process_mouse_movement(self, xoffset, yoffset, constrain_pitch=True):
        xoffset *= self.mouse_sensitivity
        yoffset *= self.mouse_sensitivity
        self.yaw += xoffset
        self.pitch += yoffset
        if constrain_pitch:
            self.pitch = max(-89.0, min(89.0, self.pitch))
        self.update_camera_vectors()

    def update_camera_vectors(self):
        front = np.array([
            math.cos(math.radians(self.yaw)) * math.cos(math.radians(self.pitch)),
            math.sin(math.radians(self.pitch)),
            math.sin(math.radians(self.yaw)) * math.cos(math.radians(self.pitch))
        ], dtype=np.float32)
        self.front = front / np.linalg.norm(front)
        self.right = np.cross(self.front, self.world_up)
        self.right = self.right / np.linalg.norm(self.right)
        self.up = np.cross(self.right, self.front)
        self.up = self.up / np.linalg.norm(self.up)

# Look-at matrix helper
def look_at(position, target, up):
    z = position - target
    z = z / np.linalg.norm(z)
    x = np.cross(up, z)
    x = x / np.linalg.norm(x)
    y = np.cross(z, x)
    view = np.eye(4, dtype=np.float32)
    view[0, :3] = x
    view[1, :3] = y
    view[2, :3] = z
    view[0, 3] = -np.dot(x, position)
    view[1, 3] = -np.dot(y, position)
    view[2, 3] = -np.dot(z, position)
    return view


# Helper function to create a box as 6 faces (each face = 2 triangles)
def create_cuboid(center, size_x, size_y, size_z, color):
    cx, cy, cz = center
    hx, hy, hz = size_x / 2.0, size_y / 2.0, size_z / 2.0
    # 8 corners
    corners = [
        [cx - hx, cy - hy, cz - hz], # 0: left-bottom-back
        [cx + hx, cy - hy, cz - hz], # 1: right-bottom-back
        [cx + hx, cy + hy, cz - hz], # 2: right-top-back
        [cx - hx, cy + hy, cz - hz], # 3: left-top-back
        [cx - hx, cy - hy, cz + hz], # 4: left-bottom-front
        [cx + hx, cy - hy, cz + hz], # 5: right-bottom-front
        [cx + hx, cy + hy, cz + hz], # 6: right-top-front
        [cx - hx, cy + hy, cz + hz], # 7: left-top-front
    ]
    # Each face: 2 triangles
    faces = [
        # Bottom
        [0, 1, 5, 4],
        # Top
        [3, 2, 6, 7],
        # Front
        [4, 5, 6, 7],
        # Back
        [0, 1, 2, 3],
        # Left
        [0, 4, 7, 3],
        # Right
        [1, 5, 6, 2],
    ]
    vertices = []
    for face in faces:
        a, b, c, d = face
        # Triangle 1: a, b, c
        vertices += corners[a] + color
        vertices += corners[b] + color
        vertices += corners[c] + color
        # Triangle 2: c, d, a
        vertices += corners[c] + color
        vertices += corners[d] + color
        vertices += corners[a] + color
    return vertices

def create_table_data():
    squares = []
    #table top
    tabletop_length = 2.0
    tabletop_width = 1.0
    tabletop_thickness = 0.1
    color_top = [0.85, 0.72, 0.52]  #light brown
    squares += create_cuboid(
        center=[0.0, 0.5, 0.0],
        size_x=tabletop_length,
        size_y=tabletop_thickness,
        size_z=tabletop_width,
        color=color_top
    )
    #table legs
    size_leg = 0.15
    height_leg = 0.5
    color_leg = [0.8, 0.4, 0.1]  #dark orange
    leg_x = tabletop_length / 2 - size_leg / 2
    leg_z = tabletop_width / 2 - size_leg / 2
    leg_positions = [
        [leg_x, 0.5 - tabletop_thickness/2 - height_leg/2, leg_z],
        [-leg_x, 0.5 - tabletop_thickness/2 - height_leg/2, leg_z],
        [leg_x, 0.5 - tabletop_thickness/2 - height_leg/2, -leg_z],
        [-leg_x, 0.5 - tabletop_thickness/2 - height_leg/2, -leg_z]
    ]
    for x, y, z in leg_positions:
        squares += create_cuboid(
            center=[x, y, z],
            size_x=size_leg,
            size_y=height_leg,
            size_z=size_leg,
            color=color_leg
        )
    return np.array(squares, dtype=np.float32)

# Vertex shader
vertex_shader_source = """
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
out vec3 ourColor;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    ourColor = aColor;
}
"""

# Fragment shader
fragment_shader_source = """
#version 330 core
in vec3 ourColor;
out vec4 FragColor;
void main()
{
    FragColor = vec4(ourColor, 1.0);
}
"""

def compile_shader(source, shader_type):
    shader = glCreateShader(shader_type)
    glShaderSource(shader, source)
    glCompileShader(shader)
    if not glGetShaderiv(shader, GL_COMPILE_STATUS):
        error = glGetShaderInfoLog(shader).decode()
        print(f"Shader compilation error: {error}")
        return None
    return shader

def create_shader_program():
    vertex_shader = compile_shader(vertex_shader_source, GL_VERTEX_SHADER)
    fragment_shader = compile_shader(fragment_shader_source, GL_FRAGMENT_SHADER)
    program = glCreateProgram()
    glAttachShader(program, vertex_shader)
    glAttachShader(program, fragment_shader)
    glLinkProgram(program)
    if not glGetProgramiv(program, GL_LINK_STATUS):
        error = glGetProgramInfoLog(program).decode()
        print(f"Program linking error: {error}")
        return None
    glDeleteShader(vertex_shader)
    glDeleteShader(fragment_shader)
    return program

def create_view_matrix(eye, target, up):
    f = np.array(target) - np.array(eye)
    f = f / np.linalg.norm(f)
    u = np.array(up)
    s = np.cross(f, u)
    s = s / np.linalg.norm(s)
    u = np.cross(s, f)
    view = np.eye(4, dtype=np.float32)
    view[0, :3] = s
    view[1, :3] = u
    view[2, :3] = -f
    view[0, 3] = -np.dot(s, eye)
    view[1, 3] = -np.dot(u, eye)
    view[2, 3] = np.dot(f, eye)
    return view

def create_perspective_matrix(fov, aspect, near, far):
    f = 1.0 / math.tan(math.radians(fov) / 2.0)
    perspective = np.zeros((4, 4), dtype=np.float32)
    perspective[0, 0] = f / aspect
    perspective[1, 1] = f
    perspective[2, 2] = (far + near) / (near - far)
    perspective[2, 3] = (2.0 * far * near) / (near - far)
    perspective[3, 2] = -1.0
    return perspective

def main():
    if not glfw.init():
        raise Exception("GLFW initialization failed")
    window = glfw.create_window(800, 600, "3D Table by Shihab", None, None)
    if not window:
        glfw.terminate()
        raise Exception("Window creation failed")
    glfw.make_context_current(window)
    glEnable(GL_DEPTH_TEST)

    # shader program
    shader_program = create_shader_program()

    # table VAO
    table_vertices = create_table_data()
    vao = glGenVertexArrays(1)
    vbo = glGenBuffers(1)
    glBindVertexArray(vao)
    glBindBuffer(GL_ARRAY_BUFFER, vbo)
    glBufferData(GL_ARRAY_BUFFER, table_vertices.nbytes, table_vertices, GL_STATIC_DRAW)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * 4, ctypes.c_void_p(0))
    glEnableVertexAttribArray(0)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * 4, ctypes.c_void_p(3 * 4))
    glEnableVertexAttribArray(1)

    # Camera setup for perspective view
    camera = Camera(position=[0.0, 1.2, 3.5], yaw=-90.0, pitch=-20.0)
    first_mouse = True
    last_x = 400
    last_y = 300

    # Mouse callback
    def mouse_callback(window, xpos, ypos):
        nonlocal first_mouse, last_x, last_y
        if first_mouse:
            last_x = xpos
            last_y = ypos
            first_mouse = False
        xoffset = xpos - last_x
        yoffset = last_y - ypos
        last_x = xpos
        last_y = ypos
        camera.process_mouse_movement(xoffset, yoffset)

    glfw.set_cursor_pos_callback(window, mouse_callback)
    glfw.set_input_mode(window, glfw.CURSOR, glfw.CURSOR_DISABLED)

    # Projection matrix
    projection = create_perspective_matrix(45.0, 800/600, 0.1, 100.0)

    # Uniform locations
    glUseProgram(shader_program)
    model_loc = glGetUniformLocation(shader_program, "model")
    view_loc = glGetUniformLocation(shader_program, "view")
    proj_loc = glGetUniformLocation(shader_program, "projection")
    glUniformMatrix4fv(proj_loc, 1, GL_FALSE, projection.T)

    # Render loop
    while not glfw.window_should_close(window):
        # Keyboard camera view controls (set position and orientation)
        if glfw.get_key(window, glfw.KEY_L) == glfw.PRESS:
            camera.position = np.array([-2.5, 2.5, 2.5], dtype=np.float32)  # Top left angle
            camera.yaw = -45.0  # Look toward center from top left
            camera.pitch = -30.0
            camera.update_camera_vectors()
        if glfw.get_key(window, glfw.KEY_R) == glfw.PRESS:
            camera.position = np.array([2.5, 2.5, 2.5], dtype=np.float32)   # Top right angle
            camera.yaw = -135.0  # Look toward center from top right
            camera.pitch = -30.0
            camera.update_camera_vectors()
        if glfw.get_key(window, glfw.KEY_T) == glfw.PRESS:
            camera.position = np.array([0.0, 4.0, 0.0], dtype=np.float32)   # Top
            camera.yaw = -90.0
            camera.pitch = -89.0
            camera.update_camera_vectors()
        if glfw.get_key(window, glfw.KEY_D) == glfw.PRESS:
            camera.position = np.array([0.0, -2.0, 0.0], dtype=np.float32)  # Bottom
            camera.yaw = -90.0
            camera.pitch = 89.0
            camera.update_camera_vectors()
        # Zoom out view (Z key) ,Toggle zoom on Z key
        if not hasattr(camera, 'zoomed_out'):
            camera.zoomed_out = False
            camera.prev_position = camera.position.copy()
            camera.prev_yaw = camera.yaw
            camera.prev_pitch = camera.pitch
        if glfw.get_key(window, glfw.KEY_Z) == glfw.PRESS:
            if not camera.zoomed_out:
                camera.prev_position = camera.position.copy()
                camera.prev_yaw = camera.yaw
                camera.prev_pitch = camera.pitch
                camera.position = np.array([0.0, 2.0, 7.0], dtype=np.float32)
                camera.yaw = -90.0
                camera.pitch = -20.0
                camera.zoomed_out = True
                camera.update_camera_vectors()
                while glfw.get_key(window, glfw.KEY_Z) == glfw.PRESS:
                    glfw.poll_events()
            else:
                camera.position = camera.prev_position
                camera.yaw = camera.prev_yaw
                camera.pitch = camera.prev_pitch
                camera.zoomed_out = False
                camera.update_camera_vectors()
                while glfw.get_key(window, glfw.KEY_Z) == glfw.PRESS:
                    glfw.poll_events()

        if glfw.get_key(window, glfw.KEY_ESCAPE) == glfw.PRESS:
            glfw.set_window_should_close(window, True)
        glClearColor(0.2, 0.2, 0.25, 1.0)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        glUseProgram(shader_program)
        glBindVertexArray(vao)

        # Camera view matrix
        view = camera.get_view_matrix()
        glUniformMatrix4fv(view_loc, 1, GL_FALSE, view.T)

        # Model matrix (identity)
        model = np.eye(4, dtype=np.float32)
        glUniformMatrix4fv(model_loc, 1, GL_FALSE, model.T)
        glDrawArrays(GL_TRIANGLES, 0, len(table_vertices) // 6)
        glfw.swap_buffers(window)
        glfw.poll_events()
    glDeleteVertexArrays(1, [vao])
    glDeleteBuffers(1, [vbo])
    glDeleteProgram(shader_program)
    glfw.terminate()

if __name__ == "__main__":
    main()