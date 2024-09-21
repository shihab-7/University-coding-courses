package finalexam;
import javax.swing.JOptionPane;
public class YN {
    public static void main(String[] args) {
       int op =  JOptionPane.showConfirmDialog(null,"Procceed ? ","Pop up", JOptionPane.YES_NO_CANCEL_OPTION);
       if(op == JOptionPane.YES_OPTION)
       {
           System.exit(0);
       }
       else if(op == JOptionPane.CANCEL_OPTION)
       {
           System.out.println("hello");
       }
       else{
           System.out.println("You pressed no !");
       }
    }
}
