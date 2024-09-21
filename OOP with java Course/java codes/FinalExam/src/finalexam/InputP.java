package finalexam;
import javax.swing.JOptionPane;
import javax.swing.ImageIcon;
public class InputP {
    public static void main(String[] args) {
        ImageIcon pic = new ImageIcon("path of our image");
//        System.out.println(icon);
        // taking input from user through pop up box
        String name = JOptionPane.showInputDialog("Enter a name");
        // showing information to the user through customized message pop up box
        JOptionPane.showMessageDialog(null, name+" Congrats you got it !","Title",JOptionPane.PLAIN_MESSAGE, pic);
    }
}
