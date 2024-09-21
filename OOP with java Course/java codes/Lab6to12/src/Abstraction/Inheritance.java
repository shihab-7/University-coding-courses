package Abstraction;
// multiple inheritance achieved by interfaces
public class Inheritance implements InterFace1,InterFace2 {
    @Override
    public void m(){
        System.out.println("Interface1 overridden");
        System.out.println("Value of x from interface1 = "+x);
    }
    @Override
    public void m2(){
        System.out.println("Interface2 overridden");
    }
}
