package university;
public class Inh2 extends Inhr1 {
    
    public static void main(String[] args) {
        Inh2 ob = new Inh2();
        ob.a=24;
        ob.d();
    }
}

// default members can be only accessable within same pacage
// access modifiers : private, public, protected.
// private can be used in same class .