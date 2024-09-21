package oopassignment;
import java.util.TreeMap;
public class Oopassignment {
    public static void main(String[] args) {
        TreeMap<Integer,String>tmap = new TreeMap<>();
        tmap.put(1,"apple");
        tmap.put(2,"banana");
        tmap.put(3,"grape");
        tmap.put(4,"dates");
        System.out.println("All pair of treemap : "+tmap);
        tmap.remove(2);
        System.out.println("After removing key 2 : "+tmap);
    }
}
