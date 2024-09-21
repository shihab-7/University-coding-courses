package lab3;
public class Non_static {
    int a = 10; // non-static variable
    static int b = 20; // static variable
    void dis1(){
        System.out.println(a);
        dis2();  // static method called inside non-static method
    }
    static void dis2(){
        System.out.println(b); // only static elements are accessible inside a static method
    }
    public static void main(String[] args) {
        Non_static ob = new Non_static();
        ob.dis1();
    }
}
