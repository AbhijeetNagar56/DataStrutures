package Algorithms;
import java.util.Stack;


public class palindrome {
    public static boolean ispd(String s){
        int n = s.length();
        Stack<Character> stk = new Stack<>();
        for (int i = 0; i < (n/2); i++) {
            stk.push(s.charAt(i));
        }
        int start = (n % 2 == 0) ? (n / 2) : (n / 2 + 1); 
        for (int i = start; i < n; i++) {
            if(stk.isEmpty() || stk.pop()!=s.charAt(i)){
                return false;
            }
        }
        return stk.isEmpty();
    }

    public static void main(String[] args) {
        String a = "abba";
        String res = ispd(a) ? "Yes" : "No";
        System.out.println(res);
    }
}
