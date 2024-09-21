package MultiThread;
public class B implements Runnable{
    public void run(){
        for(char a='a';a<'f';a++){
            System.out.println(a);
        }
        try{
            Thread.sleep(1000);
        }catch(InterruptedException e){
            System.out.println(e);
        }
    }
}
