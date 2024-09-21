package basicjavabeginers;
import java.util.Scanner;
public class ArrayInJava {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        //array structure or declaration
        System.out.println("Enter array size : ");
        int n = input.nextInt();
        int[] Array = new int[n];
        System.out.println("Enter array elements : ");
        for(int i=0; i<n; i++)
        {
            Array[i] = input.nextInt();
        }
        System.out.print("Sum of your array : ");
        int sum =0;
        for(int i=0; i<n; i++)
        {
            sum = sum + Array[i];
        }
        System.out.println(sum);
    }
}
