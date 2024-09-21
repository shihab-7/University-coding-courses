package assignmenttreemap;
import java.util.TreeMap;
public class NullPointer {
    public static void main(String[] args) { //NullPointerException
        try{
            TreeMap<Integer,String> tree_map = new TreeMap<>();
            tree_map.put(1,"jahid");
            tree_map.put(34,"soumic");
            tree_map.put(29,"alvi");
            tree_map.put(null,"emon"); // set null as a key      
        }catch(NullPointerException e){
            System.out.println(e);
        }
    }
}
