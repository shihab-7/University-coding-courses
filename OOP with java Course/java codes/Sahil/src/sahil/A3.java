package sahil;
public class A3 {
    static int count = 0;
    void dis(){
        count++;
        System.out.println(count);
    }
    public static void main(String[] args) {
        A3 obj1 = new A3();
        obj1.dis();
        A3 obj2 = new A3();
        obj2.dis();
        A3 obj3 = new A3();
        obj3.dis();
    }
}
