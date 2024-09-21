package Filepac;
public class M {
    public static void main(String[] args) {
        T thread1 =new T();
        thread1.start();
        R thread2 = new R();
        Thread thread3 = new Thread(thread2);
        thread3.start();
    }
}
