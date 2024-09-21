package labfinal;
public class D {
    int revNum(int num){
        int result = 0;
        while(num!=0){
            int digit = num % 10;
            result = result * 10 + digit;
            num = num / 10;
        }
        return result;
    }
    
    public static void main(String[] args) {
        D ob = new D();
        int myNum = ob.revNum(13);
        System.out.println(myNum);
    }
}
