package Algorithms;
public class towerOfHanoi {
    public static void solvetoh(int n, String s, String a, String e){
        if(n == 0) return;
        solvetoh( n - 1, s, e, a);
        System.out.println("Transfer disk " + n + " from " + s + " to " + e);
        solvetoh( n - 1, a, s, e);
    }
    public static void main(String[] args) {
        solvetoh(3, "A", "B", "C");
    }
}