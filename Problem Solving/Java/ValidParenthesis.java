import java.util.Stack;

public class ValidParenthesis {
    public boolean matching(char a, char b) {
        if (a == '[' && b == ']' || a == '(' && b == ')' || a == '{' && b == '}') return true;
        else return false;
    }

    public boolean isValid(String s) {
        Stack<Character> st = new Stack<Character>();
        for (int i = 0 ; i < s.length() ; i++) {
            if (s.charAt(i) == '[' || s.charAt(i) == '(' || s.charAt(i) == '{') {
                st.push(s.charAt(i));
            }
            else {
                if (!st.empty()) {
                    if (!matching(st.peek(), s.charAt(i))) {
                        return false;
                    }
                    else {
                        st.pop();
                    }
                }
                else {
                    st.push(s.charAt(i));
                }
            }
        }
        if (st.empty()) return true;
        else return false;       
    }    
}