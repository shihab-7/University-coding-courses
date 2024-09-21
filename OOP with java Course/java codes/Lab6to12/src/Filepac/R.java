package Filepac;
public class R implements Runnable {
    public void run(){
        for(int i=10;i<=15;i++){
            System.out.println(i);
        }
        try{
            Thread.sleep(1000);
        }catch(InterruptedException e){
            System.out.println(e);
        }
    }
}
