from flask import Flask, render_template,url_for,redirect,request
from flask_sqlalchemy import SQLAlchemy
from datetime import datetime
from flask_migrate import Migrate

app = Flask(__name__)

# 4 slashes for exact path for sqlite database path and 3 for relative path
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///Tasks.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)
migrate = Migrate(app,db)

# database tables
class Todo(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    content = db.Column(db.String(200), nullable=False)
    completed = db.Column(db.Integer, default=0)
    date_created = db.Column(db.DateTime, default=datetime.utcnow)
    is_done = db.Column(db.Boolean, default=False)

    # return id of each task created
    def __repr__(self):
        return '<Task %r>' % self.id



@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        task_content = request.form['content']
        new_task = Todo(content = task_content)

        try:
            db.session.add(new_task)
            db.session.commit()
            return redirect('/')
        except:
            return 'Task not added for unknown reason'
    else:
        task = Todo.query.order_by(Todo.date_created).all()
        return render_template('index.html', tasks=task)
    

@app.route('/delete/<int:id>')
def Delete(id):
    task_to_delete = Todo.query.get_or_404(id)

    try:
        db.session.delete(task_to_delete)
        db.session.commit()
        return redirect('/')
    except:
        return f'There is an issue deleting this Task {id}'
    

@app.route('/update/<int:id>', methods=['GET', 'POST'])
def Update(id):
    task = Todo.query.get_or_404(id)

    if task.is_done:
        return 'Can not update completed task'

    if request.method == 'POST':
        task.content = request.form['content']

        try:
            db.session.commit()
            return redirect('/')
        except:
            return f'There is an issue updating this Task {id}'
    else:
        return render_template('update.html',task=task)
    

@app.route('/mark_as_done/<int:id>', methods=['GET', 'POST'])
def MarkAsDone(id):
    task = Todo.query.get_or_404(id)
    task.is_done = not task.is_done

    try:
        db.session.commit()
        return redirect('/')
    except:
        return f'Unknowm issue detected updating task {id}'
    

if __name__ == '__main__':
    app.run(debug=True)