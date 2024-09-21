package university;
public class B {
    
    // in inheritance final methods can not be override
    final void d(){
        System.out.println("class final1");
    }
    public static void main(String[] args) {
        B ob = new B();
        ob.d();
    }
}
