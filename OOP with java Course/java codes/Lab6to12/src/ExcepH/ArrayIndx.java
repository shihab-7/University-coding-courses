package ExcepH;
public class ArrayIndx {
    public static void main(String[] args) {
        int [] array = new int[4];
        try{
            array[6] =100;
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println(e);
        }
    }
}
