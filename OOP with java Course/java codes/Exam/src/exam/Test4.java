package exam;
public class Test4 {
    float a,b;
    Test4(float i ,float j){
        a=i;
        b=j;
        System.out.println((i+j)/2);
        System.out.println((a+b)/2);
    }
    public static void main(String[] args) {
        Test4 ob = new Test4(2.0f,3.0f);
    }
}
