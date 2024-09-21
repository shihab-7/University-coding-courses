package lab4;
public class B {
    void sum(int ... num){ //variable length argument
        int total = 0;
        for(int x: num)  //enhanced for loop
            total+=x;
        System.out.println(total);
    }
    public static void main(String[] args) {
        B ob = new B();
        ob.sum(2,3);
        ob.sum(5,10,15);
        ob.sum(3,4,5,6,7,8);
    }
}
