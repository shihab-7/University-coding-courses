package assignmenttreemap;
import java.util.TreeMap;
import java.util.Map;
public class UnsupportedOpr {
    public static void main(String[] args) { //UnsupportedOperationException
        try{
            TreeMap<Integer,String> tree_map = new TreeMap<>();
            tree_map.put(1,"jahid");
            tree_map.put(34,"soumic");
            tree_map.put(29,"alvi");
            Map.Entry<Integer,String> key = tree_map.firstEntry();
            key.setValue("emon"); // try to use setValue() method with Map.Entry
        }catch(UnsupportedOperationException e){
            System.out.println(e);
        }
    }
}
