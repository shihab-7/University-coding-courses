package Abstraction;
public class Multiple_inhritance implements Interface_inhr {
    // java multiple inheritance support kore na but interface diye inheritance kora jay
    // r interface class er vitor j kono variable public static final diye initialize korte hobe.
    // r interface class er vitor sob method abstract hishebe likhte hobe r ei method gulo hobe public abstract
    // interface k inherit korte extends use na kore implements korte hoy
    
    @Override
    public void m(){
        System.out.println("oop");
//        System.out.println(i);
    }
    public static void main(String[] args) {
        Multiple_inhritance ob = new Multiple_inhritance();
        ob.m();
    }
}
