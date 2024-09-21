package labfinal;
public class A4 {
    int a = 100;
    
    void dis(int a){
        a = a; // self initializatio 
        System.out.println("without this keyword a = "+a);  // local variable a without using this
        System.out.println("with using this keyword a = "+this.a); // now a become instance variable
    }
    public static void main(String[] args) {
        A4 ob = new A4();
        ob.dis(25);
    }
}
