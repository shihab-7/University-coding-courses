package sahil2;
public class D1 extends D {
    int y=72;
    void dis2(){
        System.out.println(x+y);
    }
    @Override 
    void dis(){
        System.out.println(x);
    }
    public static void main(String[] args) {
        D1 ob = new D1();
        ob.dis2();
        ob.dis();
    }
}
