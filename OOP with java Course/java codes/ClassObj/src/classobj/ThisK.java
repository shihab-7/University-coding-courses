package classobj;

public class ThisK {
    int a,b; // instance var
    void dis(int a, int b){ //formal parameter 
        this.a=a; // local var
        this.b=b; // local var
        System.out.println(a+b);
    }
    public static void main(String[] args) {
        ThisK ob = new ThisK();
        ob.dis(3, 4);
    }
}
