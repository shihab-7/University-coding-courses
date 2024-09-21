package sudokuusingjavaswing;

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import java.time.LocalTime;
import java.time.Duration;

public class SudokuGame extends JFrame {
    private JTextField [][] GridCells;
    private int [][] Solution;
    private boolean[][] FixedCells;
    private LocalTime StartTime;
    private LocalTime EndTime;
    
    public SudokuGame(int difficulty){
        StartTime = LocalTime.now();
        setTitle("9 by 9 Sudoku Board");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(500,150,600,600);
        setResizable(false);
        
        // using jpanel to make sudoku grid
        JPanel SudokuPanel = new JPanel();
        GridLayout GameGrid = new GridLayout(9,9);
        SudokuPanel.setLayout(GameGrid);
        
        //initialize the gridlayout 
        GridCells = new JTextField[9][9];
        Solution = new int[9][9];
        FixedCells = new boolean[9][9];
        
        GenerateSudokuPuzzle(difficulty);
        
        // making text fields for the sudoku grid
        for(int i = 0;i<9;i++){
            for(int j = 0; j<9;j++){
                GridCells[i][j] = new JTextField(1);
                if(!FixedCells[i][j]){
                   GridCells[i][j].setBackground(Color.LIGHT_GRAY);
                   GridCells[i][j].setForeground(Color.BLACK);
                }else{
                    GridCells[i][j].setText(String.valueOf(Solution[i][j]));
                    GridCells[i][j].setEditable(false);
                    GridCells[i][j].setBackground(Color.BLACK);
                    GridCells[i][j].setForeground(Color.CYAN);
                }
                SudokuPanel.add(GridCells[i][j]);
            }
        }    
        // making frame for the sudoku panel
        getContentPane().add(SudokuPanel, BorderLayout.CENTER);
        
        JButton doneButton = new JButton("Done ...");
        doneButton.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                if(CheckSolution()){
                    EndTime = LocalTime.now();
                    Duration duration = Duration.between(StartTime, EndTime);
                    long minutes =duration.toMinutes() ;
                    long seconds = duration.minusMinutes(minutes).getSeconds();
                    String time = "Congratulation ! "+StartInterface.player_name+" You Solved the Game in \n"+String.valueOf(minutes)+" minutes "+String.valueOf(seconds)+" seconds";
//                    System.out.println(time);  // testing purpose
                    JOptionPane.showMessageDialog(SudokuGame.this,time);
                    dispose();     
                }else{
                    JOptionPane.showMessageDialog(SudokuGame.this,"Oops ! Try again ");
                    printSolution();  // this was for test purpose
                }
            } 
        });
        getContentPane().add(doneButton,BorderLayout.SOUTH);
        setLocationRelativeTo(null);
        setVisible(true);
    }
    
    private void GenerateSudokuPuzzle(int difficulty){
        Random random = new Random();
        
        // generate a fully solved board
        GenerateSolutionFully(Solution,0,0);
        
        // filling all the cells with the solution
        for(int i = 0 ;i<9;i++){
            for(int j = 0;j<9;j++){
                GridCells[i][j] = new JTextField(String.valueOf(Solution[i][j]));
                FixedCells[i][j] = true;
            }
        }
        
        // adding difficulty low , medium and hard
        int level = difficulty;
        while (level > 0){
            int row = random.nextInt(9);
            int col = random.nextInt(9);
            if(FixedCells[row][col]){
                GridCells[row][col].setText("");
                FixedCells[row][col] = false;
                level --;
            }
        }
    }
    
    private boolean GenerateSolutionFully(int [][] Board, int row, int col){
        if(row == 9){
            row = 0;
            if(++col == 9){
                return true;
            }
        }
        if(Board[row][col] !=0){
            return GenerateSolutionFully(Board, row+1,col);
        }
        for(int n = 1 ; n <= 9; n++){
            if(isValid(Board,row,col,n)){
                Board[row][col]= n;
                if(GenerateSolutionFully(Board,row+1,col)){
                    return true;
                }
                Board[row][col]=0;
            }
        }
        return false;
    }
    
    private boolean isValid(int [][]Board, int row, int col, int val){
        for(int i=0;i<9;i++){
            if(Board [row][i]== val || Board[i][col] == val || Board[3*(row / 3) + i / 3 ][ 3 * (col / 3)+ i % 3] == val ){
                return false;
            }
        }
        return true;
    }
    
    private boolean CheckSolution(){
        int [][] UserSolution = new int [9][9];
        
        // take input from user and checking validity also
        for(int i =0 ;i<9;i++){
            for(int j=0;j<9;j++){
                String input = GridCells[i][j].getText();
                if(!input.isEmpty()){
                    try{
                        int num = Integer.parseInt(input);
                        UserSolution[i][j] = num ;
                    }catch ( NumberFormatException e){
                        return false; //error message box will activate  
                    }
                }else{
                    return false;  //error message box will activate 
                }
            }
        }
        for(int i = 0;i<9;i++){
            for(int j =0 ;j< 9 ;j++){
                if( UserSolution[i][j] != Solution[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    // method to see the exact solution of the generated board , it was for test purpose
     private void printSolution() {
    System.out.println("Solved Sudoku Puzzle:");
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        System.out.print(Solution[i][j] + " ");
      }
      System.out.println();
    }
  }
}