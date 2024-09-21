package sahil;
public class A2 {
    int count = 0;
    void dis(){
        count ++;
        System.out.println(count);
    }
    public static void main(String[] args) {
        A2 obj1 = new A2();
        obj1.dis();
        A2 obj2 = new A2();
        obj2.dis();
        A2 ob3 = new A2();
        ob3.dis();
    }
}
