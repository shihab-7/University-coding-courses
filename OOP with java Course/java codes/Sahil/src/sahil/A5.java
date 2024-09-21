package sahil ;
public class A5 {
    int a = 10;
    static int b = 20;
    void dis1(){
        System.out.println(a);
        dis2();
    }
    static void dis2(){
        System.out.println(b) ;
    }
    public static void main(String[] args) {
        A5 ob = new A5() ;
        ob.dis1() ;
    }
}