import java.util.Scanner;

public class test3 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i = 0; i < n; i++) {
            problem1(sc);
        }
        
    }

    public static void problem1(Scanner sc){

        long a = sc.nextInt();
        long b = sc.nextInt();

        long range = b-a;
        if(range == 0 ){
            System.out.println(1);
            return;
        }
        if(range == 1 ){
            System.out.println(2);
            return;
        }

        double ans = Math.sqrt(-1 + (8*range))/2 +0.5;

        

        System.out.println((int) Math.floor(ans));
    }
    
}
