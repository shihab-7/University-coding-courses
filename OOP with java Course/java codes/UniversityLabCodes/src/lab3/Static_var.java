package lab3;
public class Static_var {
    static int count = 0; // static variable
    void dis(){
        count ++;
        System.out.println(count);
    }
    public static void main(String[] args) {
        Static_var ob1 = new Static_var();
        ob1.dis();
        Static_var ob2 = new Static_var();
        ob2.dis();
        Static_var ob3 = new Static_var();
        ob3.dis();
    }
}
