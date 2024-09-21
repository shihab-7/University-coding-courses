package javabeginers;
public class A4 extends A1{
    public static void main(String[] args) {
        A1 obj1 = new A1();
        A2 obj2 = new A2();
        A3 obj3 = new A3();
        A4 obj4 = new A4();
        
        System.out.println(obj1 instanceof A1);
        System.out.println(obj1 instanceof A2);
        System.out.println(obj3 instanceof A1);
        System.out.println(obj2 instanceof A3);
    }
}