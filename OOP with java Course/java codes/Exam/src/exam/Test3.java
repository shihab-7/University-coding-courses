package exam;

public class Test3 {
    void add(int a, int b){
        a=a;
        b=b;
    }
    void add(int a, int b, int c){
        a=a;
        b=b;
        c=c;
    }
    public static void main(String[] args) {
        Test3 a = new Test3();
        a.add(13,12);
        a.add(1,2,3);
        
    }
}
