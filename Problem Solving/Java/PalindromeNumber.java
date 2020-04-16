
public class PalindromeNumber {
    public boolean isPalindrome(int x) {
        long init = x, rev = 0;
        while (x > 0) {
            long lastDigit = x % 10;
            rev = rev * 10 + lastDigit;
            x /= 10;
        }
        return (init == rev);
    }
}