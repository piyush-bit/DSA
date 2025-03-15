import java.util.Scanner;

public class test2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i = 0; i < n; i++) {
            problem1(sc);
        }
        
    }

    public static void problem1(Scanner sc){
        int a = sc.nextInt();
        sc.nextLine();
        String b = sc.nextLine();
        int firstZeroIndex = -1;

        if(a < 9 ) {
            if(a==1){
                if(b.equals("1")){
                    System.out.println("YES");
                    return;
                }

            }else if (a==4){
                if(b.equals("1111")){
                    System.out.println("YES");
                    return;
                }

            }

            System.out.println("NO");
            return;
        }

        for(int i = 0; i < b.length(); i++) {
            if(b.charAt(i) == '0') {
                firstZeroIndex = i;
                break;
            }
        }

        if(firstZeroIndex == -1) {
            System.out.println("NO");
            return;
        } 

        int c = firstZeroIndex - 1 ; 
        
        if(c*c == a) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
