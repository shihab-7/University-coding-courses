package MultiThread;
public class A extends Thread{
    public void run(){
        for(int i = 1 ;i < 6; i++){
            System.out.println(i);
        }
        try{
            Thread.sleep(1000);
        }catch(InterruptedException e){
            System.out.println(e);
        }
    }
}
