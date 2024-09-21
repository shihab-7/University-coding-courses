package universitylabcodes;
public class This_keyword {
    int a=10,b=12;
    void dis(int a,int b){
        this.a = a;
        this.b = b;
        System.out.println(a+b);
    }
    void dis2(){
        System.out.println(a+b);
    }
    public static void main(String[] args) {
        This_keyword ob = new This_keyword();
        ob.dis(6,7);
        ob.dis2();
    }
}
