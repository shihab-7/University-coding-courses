package labfinal;
public class A6 {
    final int a = 10;
    void setA(int i){ // we can not modify final variable's value
//        a =i;
    }
    // we can only use constructor to modify final variable
    public static void main(String[] args) {
        A6 ob = new A6();
        ob.setA(3);
        System.out.println(ob.a);
    }
}
// ei code ta error dibe 
