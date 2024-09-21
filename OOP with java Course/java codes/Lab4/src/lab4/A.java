package lab4;
public class A {
    static int a,b;
    static{
        a=72;    //static block
        b=71;
    }
    void dis(){
        System.out.println(a);
        System.out.println(b);
    }
    public static void main(String[] args) {
        A ob = new A();
        ob.dis();
    }
}
