package sahil;
public class A {
    void sum(int a, int b){
        System.out.println(a+b);
    }
    void sum(int a, int b,int c){
        System.out.println(a+b+c);
    }
    void sum(int a, double b){
        System.out.println(a+b);
    }
    public static void main(String[] args) {
        A ob = new A();
        ob.sum(5, 7);
        ob.sum(10, 11, 12);
        ob.sum(5, 2.5d);
    }
}
