package labfinal;
public class Encap2 extends Encap1{
    public static void main(String[] args) {
        Encap2 ob = new Encap2();
        System.out.println("before settting value for a = "+ob.getA());
        ob.setA(100);
        System.out.println("after setting value for a = "+ob.getA());
    }
}
