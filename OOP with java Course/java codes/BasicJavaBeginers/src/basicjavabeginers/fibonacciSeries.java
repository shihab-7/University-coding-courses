package basicjavabeginers;
import java.util.Scanner;
public class fibonacciSeries {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int first =0, second=1, rest, range;
        
        System.out.print("Enter your range : ");
        range = input.nextInt();
        
        System.out.print(first+" "+second);
        for(int i=3;i<=range;i++)
        {
            rest = first + second;
            System.out.print(" "+rest);
            first = second;
            second = rest;
        }
        System.out.println();
        
        
    }
}
