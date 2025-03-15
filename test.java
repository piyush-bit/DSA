import java.util.Scanner;

/**
 * test
 */
public class test {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i = 0; i < n; i++) {
            problem1(sc);
        }
    }

    public static void problem1(Scanner sc){

        int a = sc.nextInt();
        int b = sc.nextInt();

        int twoLeft = b%2;

        if(a%2 == 1){
            System.out.println("NO");
            return;
        }

        if(twoLeft == 0){
            System.out.println("YES");
        }else{
            if(a>=2){
                System.out.println("YES");
            }else{
                System.out.println("NO");
            }
        }
    }
}