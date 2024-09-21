package lab5;
public class F extends E{
    int x = 10;
    
    @Override
    void dis()
    {
        System.out.println(x);
        System.out.println(super.x);
        System.out.println("Hello world");
        super.dis();
    }
    public static void main(String[] args) {
        F ob = new F();
        ob.dis();
    }
}
