public class LongestSubSequence {
    public static int LCS(String A, String B, int i, int j) {
        if (i >= A.length() || j >= B.length()) {
            return 0;
        } else if (A.charAt(i) == B.charAt(j)) {
            return 1 + LCS(A, B, i + 1, j + 1);
        } else {
            return Math.max(LCS(A, B, i + 1, j), LCS(A, B, i, j + 1));
        }
    }

    public static int LCSMemoization(String A, String B) {
        int[][] dp = new int[A.length() + 1][B.length() + 1];

        for (int i = 1; i <= A.length(); i++) {
            for (int j = 1; j <= B.length(); j++) {
                if (A.charAt(i - 1) == B.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[A.length()][B.length()];
    }

    public static void main(String[] args) {
        String s1 = "ABDCBA";
        String s2 = "ABCAD";
        System.out.println("Length of Longest Subsequence (DP) is " + LCSMemoization(s1, s2));
        System.out.println("Length of Longest Subsequence (Recursive) is " + LCS(s1, s2, 0, 0));
    }
}


