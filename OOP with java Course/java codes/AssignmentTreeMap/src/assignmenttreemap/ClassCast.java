package assignmenttreemap;
import java.util.TreeMap;
public class ClassCast {
    public static void main(String[] args) {   //ClassCastException
        try{
                TreeMap<Integer,String> tree_map = new TreeMap<>();
                tree_map.put(29 ,"Alvi");
                tree_map.put(34 ,"Soumik");
                tree_map.put(1 ,"Jahid");
                Object n = "C";  // non integer value
                if( n instanceof Integer)
                    tree_map.put((Integer)n,"Emon");
                else  // create new instance of classcastexception
                    throw new ClassCastException();
                // throw catch its nearest catch block
        }catch (ClassCastException e){
            System.out.println(e);
        }
    }
}
