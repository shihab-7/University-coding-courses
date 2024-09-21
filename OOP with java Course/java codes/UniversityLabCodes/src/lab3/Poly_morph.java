package lab3;
public class Poly_morph {
    void sum(int a, int b){
        System.out.println(a+b);
    }
    void sum(int a, int b, int c){
        System.out.println(a+b+c);
    }
    void sum(int a, double b){
        System.out.println(a+b);
    }
    public static void main(String[] args) {
        Poly_morph ob = new Poly_morph();
        ob.sum(2, 4);
        ob.sum(6, 2.5d);
        ob.sum(2, 8, 6);
    }
}
