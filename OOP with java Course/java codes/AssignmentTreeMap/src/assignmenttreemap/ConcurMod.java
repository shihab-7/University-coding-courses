package assignmenttreemap;
import java.util.TreeMap;
import java.util.Iterator;
import java.util.ConcurrentModificationException;
public class ConcurMod {
    public static void main(String[] args) { 
//ConcurrentModificationException
        try{
                TreeMap<Integer,String> tree_map = new TreeMap<>();
                tree_map.put(1,"Fish");
                tree_map.put(2,"Bird");
                tree_map.put(3,"Cat");
                System.out.println(tree_map);
                Iterator<Integer> it = tree_map.keySet().iterator();
                while(it.hasNext()){
                    Integer key = it.next();
                    if(key == 2) tree_map.put(4, "Dog"); // modifying
                }
        }catch(ConcurrentModificationException e){
            System.out.println(e);
        }
    }
}
