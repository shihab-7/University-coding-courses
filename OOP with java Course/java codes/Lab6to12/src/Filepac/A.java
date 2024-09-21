package Filepac;
import java.io.File;
import java.io.IOException;
import java.util.Formatter;
import java.io.FileNotFoundException;
public class A {
    public static void main(String[] args) {
        File f1 = new File("DIU CSE");
        f1.mkdir(); // to make directory
        String s = f1.getAbsolutePath(); // to see the folder path
        System.out.println(s);
        System.out.println(f1.getName());
        File text = new File(s+"/cse.txt");
       try{
           text.createNewFile();
       }catch(IOException e){
           System.out.println(e);
       }
       String name = "Ulfat";
       int roll = 19;
       try{
           Formatter f = new Formatter(text);
           f.format("name : %s  , roll : %d",name,roll);
           f.close();
       }catch(FileNotFoundException e){
           System.out.println(e);
       }
    }
}
