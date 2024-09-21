package presentation;
import java.util.TreeMap;
import java.util.Scanner;
import java.util.Map;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Formatter;
public class Presentation {
    public static void main(String[] args) {
        TreeMap<Integer,String>tree_map = new TreeMap<>();
        Scanner input = new Scanner(System.in);
        System.out.println("Enter total number of students in the class : ");
        int TotalStudents = input.nextInt();
        input.nextLine();
        System.out.println("Enter your name then after a space enter roll : ");
        try{
            for(int i = 0 ; i < TotalStudents ; i++){
                String Data = input.nextLine();
                String [] array = Data.split(" ");
                String name = array[0];
                Integer roll=null;
                try{
                    roll = Integer.parseInt(array[1]);
                }catch(NumberFormatException e){
                    System.out.println(e);
                }
                tree_map.put(roll, name);
            }
        }catch(NullPointerException e){
            System.out.println(e);
        }
        try{
            File folder = new File("Batch D-72");
            File myfile = new File(folder.getAbsolutePath()+"/PresentStudents.txt");
            try{
                folder.mkdir();
                myfile.createNewFile();
            }catch(Exception e){
                System.out.println(e);
            }
            try{
                Formatter f = new Formatter(myfile);
                for(Map.Entry<Integer,String> s : tree_map.entrySet()){
                    f.format("Name : %s  Roll : %d%n",s.getValue(),s.getKey());
                }
                f.close();
                System.out.println("Your text file has been created successfully in the folder : "+folder.getName());
            }catch(FileNotFoundException e){
                System.out.println(e);
            }
        }catch(NullPointerException e){
                System.out.println(e);
        }catch(Exception e){
            System.out.println(e);
        }
    }
}