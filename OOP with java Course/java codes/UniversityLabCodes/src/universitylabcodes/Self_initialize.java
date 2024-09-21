package universitylabcodes;
public class Self_initialize {
    int a = 10, b = 12;
    void dis(int a, int b){
        a = a;
        b = b;
        System.out.println(a+b);
    }
    void dis2(){
        System.out.println(a+b);
    }
    public static void main(String[] args) {
        Self_initialize ob = new Self_initialize();
        ob.dis(6,7);
        ob.dis2();
    }
}
