package labcode;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Formatter;
public class LabCode {
    boolean CheckFibo(int n){
        if(n==0) return true;
        int num1=0;
        int num2=1;
        while(num2 < n){
            int tmp = num2;
            num2+=num1;
            num1=tmp;
        }
        if(num2==n)return true;
        else return false;
    }  
    public static void main(String[] args) {
       LabCode ob = new LabCode();
//        System.out.println(ob.CheckFibo(10));
      Scanner input = new Scanner(System.in);
      File folder = new File("MyFiboFolder");
      File fibo = new File(folder.getAbsolutePath()+"/fibo.txt");
      File non_fibo = new File(folder.getAbsolutePath()+"/non_fibo.txt");
      Formatter f1 = null;
      Formatter f2 = null;
      try{ 
          folder.mkdir();
          fibo.createNewFile();
          non_fibo.createNewFile();
          f1 = new Formatter(fibo);
          f2 = new Formatter(non_fibo);
          System.out.println("Enter any number to check that exist or not in fibonacci series : ");
          System.out.println("Enter e to exit the program : ");        
          while(true){
                String n = input.nextLine();
                if("e".equals(n)) break;
                try{
                    int num = Integer.parseInt(n);
                    if(ob.CheckFibo(num)) f1.format("Fibonacci numbers  : %d \n",num); 
                    else f2.format("Non-fibonacci numbers  : %d \n",num);       
                    }catch(NumberFormatException e){
                        System.out.println(e);
                    }
            }
        }catch(FileNotFoundException e){
            System.out.println(e);
        }catch(Exception e4){
             System.out.println(e4);
        }finally{
            if(f1 != null) f1.close();
            if(f2 != null) f2.close();
            System.out.println("For fibo numbers check file : "+fibo.getName()+" in "+fibo.getAbsolutePath());
            System.out.println("For nonfibo numbers check file : "+non_fibo.getName()+" in "+non_fibo.getAbsolutePath());
        }
    }
}
