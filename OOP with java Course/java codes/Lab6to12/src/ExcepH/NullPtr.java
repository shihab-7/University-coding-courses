package ExcepH;
public class NullPtr {
    public static void main(String[] args) {
        String s = null;
        try{
            System.out.println(s.charAt(0));
        }catch(NullPointerException e){
            System.out.println(e);
        }
    }
}
