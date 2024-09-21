package lab4;
public class D72_a extends D71_a { //single inheritance
    int y=72;
    void dis2(){
        System.out.println(x+y);
    }
    @Override   // method override
    void dis(){
        System.out.println(x);
    }
    public static void main(String[] args) {
        D72_a ob = new D72_a();
        ob.dis2();
        ob.dis();
    }
}
