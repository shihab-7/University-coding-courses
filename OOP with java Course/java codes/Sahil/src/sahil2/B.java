package sahil2;
public class B {
    void sum(int ... num){
        int answer = 0;
        for(int x: num) 
            answer+=x;
        System.out.println(answer);
    }
    public static void main(String[] args) {
        B ob = new B();
        ob.sum(2,3);
        ob.sum(5,10,15);
        ob.sum(1,2,3,4,5,6,7);
    }
}
