package ExcepH;
public class ArithM {
    public static void main(String[] args) {
        int x = 11;
        int y = 0;
        try{
            System.out.println(x/y);
        }catch(ArithmeticException e){
            System.out.println(e);
        }
    }
}
