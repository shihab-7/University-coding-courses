package javabeginers;
public class B2 extends B1 {
    int a = 10;
    void dis(){
        System.out.println(a);
        System.out.println(super.a);
    }
    public static void main(String[] args) {
        B2 obj = new B2();
        obj.dis();
    }
}
