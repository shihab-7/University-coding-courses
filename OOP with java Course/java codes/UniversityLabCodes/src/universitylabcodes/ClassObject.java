package universitylabcodes;

public class ClassObject {
    int roll;
    void display()
    {
        System.out.println(roll);
    }
    public static void main(String[] args) {
        ClassObject obj;
        obj = new ClassObject();
        obj.roll = 11;
        obj.display();
    }
}
