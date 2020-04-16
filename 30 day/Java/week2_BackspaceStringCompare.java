
public class week2_BackspaceStringCompare {
    public boolean backspaceCompare(String S, String T) {
        String s = "";
        String t = "";
        for (int i = 0 ; i < S.length() ; i++) {
            if (S.charAt(i) == '#') {
                if (s.length() != 0) s = s.substring(0, s.length() - 1);
            }
            else s += S.charAt(i);
        }

        for (int i = 0 ; i < T.length() ; i++) {
            if (T.charAt(i) == '#') {
                if (t.length() != 0) t = t.substring(0, t.length() - 1);
            }
            else t += T.charAt(i);
        }

        return s.equals(t);
    }
}