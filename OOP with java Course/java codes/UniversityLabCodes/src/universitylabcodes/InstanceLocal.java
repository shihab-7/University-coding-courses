package universitylabcodes;
public class InstanceLocal {
    int x , y ;
    InstanceLocal(){
        System.out.println(" New Program ! ");
    }
    InstanceLocal(int i, int j){
        x=i;
        y=j;
    }
    void dis(){
        System.out.println(x+y);
    }
    public static void main(String[] args) {
        InstanceLocal obj = new InstanceLocal();
        InstanceLocal obj1 = new InstanceLocal(5,7);
//        obj.dis();
        obj1.dis();
    }
}
