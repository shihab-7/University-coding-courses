package sahil2;
public class A {
    static int a,b;
    static{
        a=72;
        b=71;
    }
    void dis(){
        System.out.println(a);
        System.out.println(b);
    }
    public static void main(String[] args) {
        A a = new A();
        a.dis();
    }
}