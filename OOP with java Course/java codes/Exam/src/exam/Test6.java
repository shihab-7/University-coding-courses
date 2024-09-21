package exam;
public class Test6 {
    int count =0;
    Test6(){
        count++;
        System.out.println(count);
    }
    public static void main(String[] args) {
        Test6 ob1 = new Test6();
        Test6 ob2 = new Test6();
        Test6 ob3 = new Test6();
    }
}
