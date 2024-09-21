package classobj;
//overloading
public class PolyOvel {
    void dis(int a, int b){
        System.out.println(a);
    }
    float dis(float a){
        System.out.println(a);
        return a;
    }
    float dis(float a, int b){
        return b;
    }
    double dis(int s,float p){
        return p;
    }
    public static void main(String[] args) {
        PolyOvel o = new PolyOvel();
        o.dis(3);
    }
}
