package lab6to12;
public class StatFinal {
    final static int a=10 ; 
    final static int b; // it is a blank final static variable late initilized inside static block
    static{
        b=20;
    }
    public static void main(String[] args) {
        System.out.println("Static variable a = "+StatFinal.a);
        System.out.println("Static variable b = "+StatFinal.b);
    }
}
