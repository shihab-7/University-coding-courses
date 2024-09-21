package basicjavabeginers;
import java.util.Scanner;


public class Array2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter number of proples :");
        int n = input.nextInt();
        String[] peoples = new String[n];
        System.out.println("Enter People's name :");
        for (int i=0;i<n;i++)
        {
            peoples[i]= input.next();
        }
        System.out.print("Names : ");
        for(String p : peoples)
        {
            System.out.print(" "+p);
        }
        System.out.println();
    }
}
