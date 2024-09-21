package assignmenttreemap;
import java.util.Iterator;
import java.util.TreeMap;
import java.util.NoSuchElementException;
public class NoSuchElm {
    public static void main(String[] args) { //NoSuchElementException
        try{
            TreeMap<Integer,String> tree_map = new TreeMap<>();
                Iterator<Integer> it = tree_map.keySet().iterator();
                Integer key = it.next(); // try to access an empty treemap key
        }catch (NoSuchElementException e){
            System.out.println(e);
        }
    }
}
