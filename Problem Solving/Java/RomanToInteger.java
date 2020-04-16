
public class RomanToInteger {
    public boolean isSpecial(String sub) {
        if (sub.equals("IV") || sub.equals("IX") || sub.equals("XL") || sub.equals("XC") || sub.equals("CD") || sub.equals("CM")) return true; 
        return false;
    }
    public int convert(String sub) {
        int res = 0;
        if (isSpecial(sub) == true) {
            switch (sub) {
                case "IV" : return 4;
                case "IX" : return 9;
                case "XL" : return 40;
                case "XC" : return 90;
                case "CD" : return 400;
                case "CM" : return 900;
            }
        }
        else {
            sub = sub.substring(0,1);
            switch (sub) {
                case "I" : return 1;
                case "V" : return 5;
                case "X" : return 10;
                case "L" : return 50;
                case "C" : return 100;
                case "D" : return 500;
                case "M" : return 1000;
            }
        }
        return res;
    }

    public int romanToInt(String s) {
        int res = 0;
        for (int i = 0 ; i < s.length() ; i++) {
            if (i == s.length() - 1) {
                String sub = s.substring(i);
                res += convert(sub);
            }
            else {
                String sub = s.substring(i, i+2);
                if (isSpecial(sub)) i++;
                res += convert(sub);
            }
        }
        return res;
    }
}