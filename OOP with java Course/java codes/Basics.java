public class Basics {

    int i = 4;
    public static void main(String[] args) {

        // Basics k = new Basics();

        int n = 0;
        do
        {
            System.out.println(n);
            ++n;
        }
        while(n>1);

        // if (k.i>1){

        //     switch (k.i) {
        //         case 0: System.out.println(" 0 got you"); 
        //         break;
        //         case 1: System.out.println(" 1 got you");
        //         break;
        //         case 4: System.out.println(" 4 got you");
        //         break;
        //         default: System.out.println("opps!");
        //     }

        // }
        // else if (k.i>1) System.out.println("Noo!");
        // else System.out.println("out");

        for (int i = 0; i<8; i++) System.out.println(i);

        System.out.println("\n");
            // for each loop
        int array[]= {0,1,2,3,4,5,6};
        for (int e : array) System.out.println(e);

        System.out.println("\n");

        for (int i=0; i<6;i++)
        {
            if(i==4) continue;
            System.out.println(i);
        }

        System.out.println("\n");

        for (int i=0; i<6;i++)
        {
            if(i==4) break;
            System.out.println(i);
        }

        int [][] myNumbers = { {1, 2, 3, 4}, {5, 6, 7} };
        for (int i = 0; i < myNumbers.length; ++i) 
        {
            for(int j = 0; j < myNumbers[i].length; ++j) {
                System.out.println(myNumbers[i][j]);
            }
        }



    }
}

