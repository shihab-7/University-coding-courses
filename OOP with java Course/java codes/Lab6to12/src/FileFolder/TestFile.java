package FileFolder;
import java.io.File;
import java.util.Formatter;
import java.io.FileNotFoundException;
import java.io.IOException; // need to import this to create new file
public class TestFile {
    public static void main(String[] args){
        File folder = new File("New Folder Batch D-72");
        folder.mkdir(); // to make the folder 
        System.out.println("Folder name = "+folder.getName()+" "+"Folder path = "+folder.getAbsolutePath());   
        File story = new File(folder.getAbsolutePath()+"/story.txt");
        try{
            story.createNewFile();// created a file named story.txt inside the directory we just made
        }catch(IOException e1){
            System.out.println(e1);
        }     
        String s = "We are the students of Dhaka International University Batch-";
        int a = 72;
        try{
            Formatter f = new Formatter(story);
            f.format("\t\tStory\n%s%d\n",s,a);
            f.close();
        }catch(FileNotFoundException e2){
            System.out.println(e2);
        } 
    }
}
