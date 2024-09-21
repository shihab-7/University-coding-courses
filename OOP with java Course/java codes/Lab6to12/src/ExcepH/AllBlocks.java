package ExcepH;
public class AllBlocks {
    public static void main(String[] args) throws StringIndexOutOfBoundsException{
        String s = null;
        try{
            try{
                System.out.println(s.charAt(0));
            }catch(NullPointerException e){
                throw new NullPointerException("it is our modified exception");
            }
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println(e);
        }catch(Exception e1){
            System.out.println(e1);
        }
        finally{
            System.out.println("We are inside finally");
        }
    }
}
