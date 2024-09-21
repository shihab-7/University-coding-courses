package sudokuusingjavaswing;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class StartInterface{
    private static JFrame nameFrame;
    private static JFrame levelFrame;
    private static JTextField nameField;
    public static String player_name; // storing name to use later
    
    // first popup view to take name input
    public void ResponseWindow(){
        nameFrame = new JFrame("Player name : ");
        nameFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        nameFrame.setBounds(600, 300,400,200);
        
        // making partision for each row like enter your name text , blank field to taka name input and submit button
        GridLayout layout = new GridLayout(3,1);
        JPanel panel = new JPanel(layout);
        JLabel nameLabel = new JLabel("Enter your name...");
        nameField = new JTextField();
        
        panel.add(nameLabel);
        panel.add(nameField);
        
        // creat submit button
        JButton submitBtn = new JButton("Submit");
        
        // customize submit button function for an onclick event
        ActionListener click = new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent a){
                String name = nameField.getText().trim();
                if(name.isEmpty())
                    JOptionPane.showMessageDialog(nameFrame,"Invalid Input", "Error", JOptionPane.ERROR_MESSAGE);
                else{
                    player_name = name;
                    LevelSelectionWindow(name);
                    nameFrame.dispose();
                } 
            }
        };
        // jpanel customization 
        panel.add(submitBtn);
        submitBtn.addActionListener(click);
        nameFrame.getContentPane().add(panel,BorderLayout.CENTER);
        nameFrame.getContentPane().add(panel,BorderLayout.SOUTH);
        nameFrame.setVisible(true);
    }
    
    // method to create difficulty selection window
    private void LevelSelectionWindow(String name){
        levelFrame = new JFrame("Select level");
        levelFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        levelFrame.setBounds(600, 300,400, 200);
        
        // making grid for each option like easy ,medium,hard , button
        GridLayout layout = new GridLayout(4,1);
        JPanel panel = new JPanel(layout);
        JLabel nameLable = new JLabel (name+" Chose level : ");
        JButton easyBtn = new JButton("Easy");
        JButton mediumBtn = new JButton("Medium");
        JButton hardBtn = new JButton("Hard");
        
        // making objects to get response for a onclick event for each level or difficulty chose by user
        ActionListener c1 = new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent a){
                JOptionPane.showMessageDialog(levelFrame, "Easy Game starting ...");
                levelFrame.dispose();
                SudokuGame ob = new SudokuGame(3);
            }
        };
        ActionListener c2 = new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent a){
                JOptionPane.showMessageDialog(levelFrame, "Medium Game starting ...");
                levelFrame.dispose();
                SudokuGame ob = new SudokuGame(7);
            }
        };
        ActionListener c3 = new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent a){
                JOptionPane.showMessageDialog(levelFrame, "Hard Game starting ...");
                levelFrame.dispose();
                SudokuGame ob = new SudokuGame(10);
            }
        };
        // add actionlisteners to the buttons
        easyBtn.addActionListener(c1);
        mediumBtn.addActionListener(c2);
        hardBtn.addActionListener(c3);
        
        // adding buttons to the jpanel
        panel.add(nameLable);
        panel.add(easyBtn);
        panel.add(mediumBtn);
        panel.add(hardBtn);
        
        // adding panel to the jframe for level frame
        levelFrame.getContentPane().add(panel,BorderLayout.CENTER);
        levelFrame.setVisible(true);
    }
    public static void main(String[] args) {
        StartInterface ob = new StartInterface();
        ob.ResponseWindow(); // this method holds all the design for frame functionality and design
    }
}