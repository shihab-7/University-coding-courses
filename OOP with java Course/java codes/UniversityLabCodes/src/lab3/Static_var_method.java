package lab3;
public class Static_var_method {
    int a = 10;
    static int b = 20;
    void dis1(){
        System.out.println(a);
        System.out.println(b);
    }
    static void dis2(){
//        System.out.println(a);
        System.out.println(b);
    }
    public static void main(String[] args) {
        Static_var_method ob1 = new Static_var_method();
        ob1.dis1();
        Static_var_method.dis2();
    }
}
