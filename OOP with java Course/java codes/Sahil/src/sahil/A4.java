package sahil;
public class A4 {
    int a = 12;
    static int b = 20;
    void dis1(){
        System.out.println(a);
        System.out.println(b);
    }
    static void dis2(){
        //System.out.println(a);
        System.out.println(b);
    }
    public static void main(String[] args) {
        A4 ob = new A4();
        ob.dis1();
        //ob.dis2();
        A4.dis2();
    }
}
