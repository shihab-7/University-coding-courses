package university;
public class B2 extends B {
    
    @Override
    void d(){
        System.out.println("class final2");
    }
    public static void main(String[] args) {
        B2 ob = new B2();
        ob.d();
    }
}
