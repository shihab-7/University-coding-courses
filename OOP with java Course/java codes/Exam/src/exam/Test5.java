package exam;

public class Test5 {
    static int a;
    static int b;
    static int c;
    static void mul(int i, int j ,int k){
        a=i;
        b=j;
        c=k;
        System.out.println(a*b*c);
    }
    public static void main(String[] args) {
        Test5 ob = new Test5();
        Test5.mul(2,3,4);
        Test5.mul(4,5,6);
    }
}
