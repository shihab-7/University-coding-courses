package lab6to12;
public class BlankFinal {
    final int a ; //blank final variable
    BlankFinal(int x){
        a=x;
    }
    public static void main(String[] args) {
        BlankFinal ob = new BlankFinal(10);
        System.out.println("blank final variable a  = "+ob.a);
    }
}
