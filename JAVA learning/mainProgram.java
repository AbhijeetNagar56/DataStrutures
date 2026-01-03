import java.util.*;

public class mainProgram {
    public static int average(int a, int b, int c) {
        int avg = a + b + c;
        return avg / 3;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();
        int n3 = sc.nextInt();

        System.out.println("Average is : " + average(n1, n2, n3));

    }
}