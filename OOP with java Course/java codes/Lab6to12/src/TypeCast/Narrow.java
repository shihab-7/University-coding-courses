package TypeCast;
public class Narrow {
    double a = 10.50;
    short x = (short) a;
    public static void main(String[] args) {
        Narrow obj = new Narrow();
        System.out.println("Bigger data type double a = "+obj.a);
        System.out.println("Double converted into short x = "+obj.x);
    }
}
