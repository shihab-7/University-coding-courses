package finalexam;
import javax.swing.JFrame;
public class FrameD extends JFrame {
    public static void main(String[] args) {
        FrameD frame = new FrameD();
        frame.setVisible(true);
//        frame.setSize(500,300);
//        frame.setLocation(400,70);
        frame.setBounds(400,70,500,300); // uporer 2 line combine kore set bounds banano
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setTitle("Frame Demo");
        frame.setResizable(false); // frame er size fixed kore deowa jay .
    }
}
