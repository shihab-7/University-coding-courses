package ExcepH;
public class StrIndx {
    public static void main(String[] args) {
        String name = "Shihab";
        try{
            System.out.println(name.charAt(10));
        }catch(StringIndexOutOfBoundsException e){
            System.out.println(e);
        }
    }
}
