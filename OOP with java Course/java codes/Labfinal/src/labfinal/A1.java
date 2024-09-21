package labfinal;
public class A1 {
    
    A1(int a,int b){
        if(a > b){
            System.out.println("greater = "+a);
        }
        else if(a==b){
            System.out.println(a+" is equal to "+b);
        }
        else {
            System.out.println("greater = "+b);
        }
    }
    public static void main(String[] args) {
        A1 ob = new A1(1,3);
    }
}
