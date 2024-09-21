public class Project {
    
    byte A = 1;
    short b = 2;
    int c = 3;
    char d = 'D';
    long e = 1L;
    float f = 1f;
    double d2 = 1d;
    boolean b2 = true;
    String s = "Hello, world!";

    void print()
    {

        System.out.println( A);
        System.out.println( b);
        System.out.println( c);
        System.out.println( d);
        System.out.println( e);
        System.out.println( f);
        System.out.println( d2);
        System.out.println( b2);
        System.out.println( s);
    }
    public static void main(String[] args)
    {
        // java data types
        Project x = new Project();
        x.print();
    }
}
