package javabeginers;
public class B4 extends B3 {
     @Override   
    void dis(){
        super.dis();
        System.out.println("child class");
    }
    public static void main(String[] args) {
        B4 obj = new B4();
        obj.dis();
    }
}
