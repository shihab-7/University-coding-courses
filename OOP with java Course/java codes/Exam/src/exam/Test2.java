
package exam;

public class Test2 {
    short a = 32767, b = 32767;
    void d(){
        System.out.println(a+b);
    }
    int add(){
        return a+b;
    }
    public static void main(String[] args) {
        Test2 a = new Test2();
        a.d();
        System.out.println(a.add());
    }
}
