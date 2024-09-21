package labfinal;
public class B extends A{ 
    // single inheritance , class b inherit class a
    public static void main(String[] args) {
        B ob = new B();
        ob.dis();
        int num = ob.a;
        System.out.println(num);
    }
}
