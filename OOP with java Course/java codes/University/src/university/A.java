package university;
public class A {
    
    //final can be used with classes ,variables and methods
    
   final  int a=10; // initialized with final can't be modified
   final int b; //it is called a blanked final variable
   //blanked final variable can be assigned with only constructor
   
   static final int c; //static blank final variable
   // to set value for static blank final variable we need a static block
   static{
       c = 20;
       System.out.println("c= "+c);
   }
   A()
   {
       b=20;
   }
    void d()
    {   
        //a=20;
        System.out.println("b= "+b);
        System.out.println("a= "+a);
    }
    public static void main(String[] args) {
        A ob = new A();
        ob.d();
    }
}
