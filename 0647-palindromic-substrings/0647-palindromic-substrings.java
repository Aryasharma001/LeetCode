public class Solution {
    boolean isPalindrome(String temp) {
        int n = temp.length();
        for (int i = 0; i < n / 2; i++) {
            if (temp.charAt(i) != temp.charAt(n - i - 1)) {
                return false;
            }
        }
        return true;
    }

    public int countSubstrings(String s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            StringBuilder temp = new StringBuilder();
            for (int j = i ; j <s.length(); j++) {
                temp.append(s.charAt(j));
                // System.out.println(temp + " ");
                if (isPalindrome(temp.toString())) {
                    count++;
                    // System.out.println(temp);
                }
            }
        }
        return count;
    }
}
