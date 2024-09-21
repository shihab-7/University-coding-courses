package lab5;
public class D extends A {
    public static void main(String[] args) {
        A ob1 = new A();
        B ob2 = new B();
        C ob3 = new C();
        D ob4 = new D();
        
        System.out.println(ob1 instanceof A);
        System.out.println(ob1 instanceof B);
        System.out.println(ob1 instanceof C);
        System.out.println(ob1 instanceof D);
        System.out.println(ob2 instanceof A);
        System.out.println(ob2 instanceof B);
        System.out.println(ob2 instanceof C);
//        System.out.println(ob2 instanceof D);
        System.out.println(ob3 instanceof A);
        System.out.println(ob4 instanceof D);
        System.out.println(ob4 instanceof A);
    }
}