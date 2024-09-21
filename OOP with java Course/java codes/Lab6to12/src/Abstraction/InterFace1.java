package Abstraction;
public interface InterFace1 {
    public final static int x = 10; 
    // int x = 10; // both are same initialization
    public abstract void m();
    // void m(); // method will automatically convert public abstract internally
}
