package assignmenttreemap;
import java.util.TreeMap;
public class IllegalArg {
    public static void main(String[] args) { //IllegalArgumentException
        try{
            TreeMap<Integer,String> tree_map = new TreeMap<>();
            tree_map.put(1,"jahid");
            tree_map.put(34,"soumic");
            //check and create new instance of IllegalArgumentException
            if(tree_map.containsKey(1)) throw new IllegalArgumentException();
            tree_map.put(1,"alvi"); // try to insert duplicate 
        }catch(IllegalArgumentException e){
            System.out.println(e);
        }
    }
}
