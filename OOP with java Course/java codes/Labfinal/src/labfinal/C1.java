package labfinal;
public class C1 {
    int a ;
    int b ;
    C1(int p, int q){
        a = p ;
        b=q;
        int total = a+b;
        System.out.println(total);
    }
    public static void main(String[] args) {
        int x = 4, y =3;
        C1 ob = new C1(x,y);
    }
}
