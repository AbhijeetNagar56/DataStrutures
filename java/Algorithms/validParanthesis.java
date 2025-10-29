package Algorithms;
import java.util.Stack;


public class validParanthesis {
    public static boolean validparen(String s) {
        Stack<Character> stk = new Stack<>();

        for(int i = 0; i < s.length(); i++) {
            if(stk.isEmpty()){
                stk.push(s.charAt(i));
                continue;
            }
            if((s.charAt(i) == ')' && stk.peek() == '(') || (s.charAt(i) == ']' && stk.peek() == '[') || (s.charAt(i) == '}' && stk.peek() == '{')){
                stk.pop();
                continue;
            }
            
            stk.push(s.charAt(i));
        }

        return stk.isEmpty();
    }
    public static void main(String[] args) {
        String test = "([{})]";
        System.out.println(validparen(test) ? "Yes" : "No");
    }
}
