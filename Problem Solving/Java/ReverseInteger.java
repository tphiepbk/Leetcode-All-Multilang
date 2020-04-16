public class ReverseInteger {
    public int reverse(int x) {
        if (x < 10 && x > -10) return x;

        boolean signCheck = false;
        if (x < 0) {
            signCheck = true;
            x *= -1;
        }

        String temp = Integer.toString(x);
        double len = temp.length() - 1;
        double numOfDigit = Math.pow(10 ,len);

        int res = 0;
        
        while (x > 0) {
            int digit = x % 10;
            x /= 10;
            res += digit * numOfDigit;
            numOfDigit /= 10;
        }

        if (res >= Math.pow(2, 31) - 1) res = 0;
        if (signCheck == true) res *= -1;
        return res;
    } 
}