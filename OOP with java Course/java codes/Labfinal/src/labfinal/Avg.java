package labfinal;
public class Avg {
    Avg(int a, int b,int c){
        float ans = (a+b+c)/3.0f;
        System.out.println(ans);
    }
    public static void main(String[] args) {
        Avg ob = new Avg(3,4,7);
    }
}
