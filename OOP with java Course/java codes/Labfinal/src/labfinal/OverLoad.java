package labfinal;
public class OverLoad {
    int sum(int a, int b){
        int y = a+b;
        return y;
    }
    float sum( float a, float b){
        float y = a+b;
        return y;
    }
    int sum(int a, int b, int c){
        int y = a+b+c;
        return y;
    }
    public static void main(String[] args) {
        OverLoad ob = new OverLoad();
        int a1 = ob.sum(3,4);
        int a2 = ob.sum(1, 5, 7);
        float a3 = ob.sum(2.3f, 1.5f);
        System.out.println(a1);
        System.out.println(a2);
        System.out.println(a3);
    }
}
