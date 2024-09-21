package basicjavabeginers;
import java.util.Scanner;
class HelloWorld {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.println("give m num=");
        int m=input.nextInt();
        System.out.println("give n num=");
        int n=input.nextInt();
        int sum=0;
        for(int i=m ; i <= n ; i++)
        {
            if(i%2 != 0)
            {
                sum = sum + i;
            }
        }
        System.out.println("answer = "+sum);
     }
 }