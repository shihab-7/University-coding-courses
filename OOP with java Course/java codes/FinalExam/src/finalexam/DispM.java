package finalexam;
import javax.swing.JOptionPane;
public class DispM {
    public static void main(String[] args) {
        JOptionPane.showMessageDialog(null, "Confirm ? ");
        JOptionPane.showMessageDialog(null, "Warning message","Pop up",JOptionPane.WARNING_MESSAGE);
        JOptionPane.showMessageDialog(null, "Error", "Notification",JOptionPane.ERROR_MESSAGE);
        JOptionPane.showMessageDialog(null, "information need ? ", "PopUp", JOptionPane.INFORMATION_MESSAGE);
        JOptionPane.showMessageDialog(null,"Question message","Ask",JOptionPane.QUESTION_MESSAGE);
        JOptionPane.showMessageDialog(null, "Pop up","nothing",JOptionPane.PLAIN_MESSAGE);
    }
}
