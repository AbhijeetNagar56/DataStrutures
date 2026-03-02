public class minimumBitwiseArray {
    public static void main(String args[]) {
        int a = -1;
        for (int i = 1; i < 17; i++) {
            if((i | i+1) == 17) {
                a = i;
                break;
            }
        }
        System.out.println(a);
    }
}