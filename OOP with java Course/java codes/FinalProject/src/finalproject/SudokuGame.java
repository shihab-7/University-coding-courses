package finalproject;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

public class SudokuGame extends JFrame {

  private JTextField[][] gridCells;
  private int[][] solution;
  private boolean[][] fixedCells;

  public SudokuGame() {
    setTitle("9 by 9 Sudoku Game");
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setBounds(500, 150, 600, 600);
    setResizable(false);
    // Create a panel to hold the Sudoku grid
    JPanel sudokuPanel = new JPanel();
    sudokuPanel.setLayout(new GridLayout(9, 9));

    // Initialize the Sudoku grid
    gridCells = new JTextField[9][9];
    solution = new int[9][9];
    fixedCells = new boolean[9][9];

    generateSudokuPuzzle();

    // Create text fields for the grid
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        gridCells[i][j] = new JTextField(1);
        if (!fixedCells[i][j]) {
          gridCells[i][j].setForeground(Color.BLUE);
        } else {
          gridCells[i][j].setText(String.valueOf(solution[i][j]));
          gridCells[i][j].setEditable(false);
          gridCells[i][j].setForeground(Color.BLACK);
        }
        sudokuPanel.add(gridCells[i][j]);
      }
    }

    // Add the Sudoku panel to the frame
    getContentPane().add(sudokuPanel,BorderLayout.CENTER);

    JButton doneButton = new JButton("Done...");
    doneButton.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        if (checkSolution()) {
          JOptionPane.showMessageDialog(SudokuGame.this, "Congratulations! You solved the puzzle!");
          printSolution();
        } else {
          JOptionPane.showMessageDialog(SudokuGame.this, "Sorry, the solution is not correct.");
        }
      }
    });
    getContentPane().add(doneButton, BorderLayout.SOUTH);
    setLocationRelativeTo(null); // Center the frame on the screen
    setVisible(true);
  }

  private void generateSudokuPuzzle() {
    Random random = new Random();
    // Generate a solved Sudoku puzzle
    generateSolution(solution, 0, 0);

    // Copy the solution to the puzzle
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        gridCells[i][j] = new JTextField(String.valueOf(solution[i][j]));
        fixedCells[i][j] = true;
      }
    }

    // Remove some numbers to create the puzzle
    int count = 3; // Adjust the count to change the difficulty level
    while (count > 0) {
      int row = random.nextInt(9);
      int col = random.nextInt(9);
      if (fixedCells[row][col]) {
        gridCells[row][col].setText("");
        fixedCells[row][col] = false;
        count--;
      }
    }
  }
  
  private boolean generateSolution(int[][] board, int row, int col) {
    if (row == 9) {
      row = 0;
      if (++col == 9) {
        return true;
      }
    }
    if (board[row][col] != 0) {
      return generateSolution(board, row + 1, col);
    }
    for (int val = 1; val <= 9; val++) {
      if (isValid(board, row, col, val)) {
        board[row][col] = val;
        if (generateSolution(board, row + 1, col)) {
          return true;
        }
        board[row][col] = 0;
      }
    }
    return false;
  }

  private boolean isValid(int[][] board, int row, int col, int val) {
    for (int i = 0; i < 9; i++) {
      if (board[row][i] == val || board[i][col] == val || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
        return false;
      }
    }
    return true;
  }

  private boolean checkSolution() {
    int[][] userSolution = new int[9][9];
    // Parse user input into 2D array
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        String text = gridCells[i][j].getText();
        if (!text.isEmpty()) {
          try {
            int num = Integer.parseInt(text);
            userSolution[i][j] = num;
          } catch (NumberFormatException e) {
            return false; // If any cell contains non-numeric input, return false
          }
        } else {
          return false; // If any cell is empty, return false
        }
      }
    }
    // Check if user solution matches the actual solution
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (userSolution[i][j] != solution[i][j]) {
          return false;
        }
      }
    }
    return true;
  }

  // created to get the game history
  private void printSolution() {
    System.out.println("Solved Sudoku Puzzle:");
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        System.out.print(solution[i][j] + " ");
      }
      System.out.println();
    }
  }
  public static void main(String[] args) {
    SudokuGame sudokuGame = new SudokuGame();
  }
}