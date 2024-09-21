package MultiThread;
public class Test {
    public static void main(String[] args) {
        A thread1 = new A();
        thread1.start();
        B obj2 = new B();
        Thread C = new Thread(obj2);
        C.start();
    }
}
