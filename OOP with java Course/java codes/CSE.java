public class CSE{
    int a , b;

    int sum(int x, int y)
    {
        return x+y;
    }

    void display()
    {
        System.out.println(sum(a,b));
    }
    
    public static void main(String[] args){
        CSE obj = new CSE();

        obj.a = 4;
        obj.b = 6;

        obj.display();
    }
}