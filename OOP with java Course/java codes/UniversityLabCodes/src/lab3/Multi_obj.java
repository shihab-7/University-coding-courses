package lab3;
public class Multi_obj {
    int count = 0;
    void dis(){
        count ++;
        System.out.println(count);
    }
    public static void main(String[] args) {
        Multi_obj ob1 = new Multi_obj();
        ob1.dis();
        Multi_obj ob2 = new Multi_obj();
        ob2.dis();
        Multi_obj ob3 = new Multi_obj();
        ob3.dis();
    }
}
