package basicjavabeginers;
import java.util.Scanner;
public class primenumberInARange {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int start , end , count=0;
        System.out.println("Enter a starting number : ");
        start = input.nextInt();
        System.out.println("Enter an ending number : ");
        end = input.nextInt();
        
        for(int i=start;i<=end;i++)
        {
            for(int j=2;j<i-1;j++)
            {
                if(i%j==0)
                {
                    count++;
                    break;
                }
            }
            if(count==0)
            {
                 System.out.println(i);
                 
            }
            count=0;
        }
    }
}
