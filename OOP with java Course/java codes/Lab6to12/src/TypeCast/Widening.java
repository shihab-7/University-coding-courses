package TypeCast;
public class Widening {
    int a = 10;
    double b = a;
    public static void main(String[] args) {
        Widening obj = new Widening();
        System.out.println("integer value a = "+obj.a);
        System.out.println("integer converted into double b = "+obj.b);
    }
}
