package Abstraction;
public class Interface implements Interface_inhr, Interface2 {
    
    @Override
    public void m(){
        System.out.println("oop");
//        System.out.println(i);
    }
    // java multiple inheritance support na korleo multiple interface implents support kore jeta multiple inheritance hishebe use hoy
    // same name a onek method thakle main class jetate interface implements korbo oitay override korte hobe nahoy error dibe
    // interface er kono object initialize kora jay na
}
