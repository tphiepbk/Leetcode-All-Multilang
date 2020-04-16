
public class LongestCommonPrefix {
    public String longestCommonPrefix(String[] strs) {
        String res = "";

        if (strs.length == 0) return res;
        if (strs.length == 1) return strs[0];

        int index = 0;
        char cur = '\0', pre = '\0';
        while (true){
            int check = 0;
            for (int i = 0 ; i < strs.length ; i++) {

                if (strs[i] == "") return "";
                
                if (index >= strs[i].length()) {
                    check++;
                    break;
                }

                if (i == 0) {
                    pre = strs[i].charAt(index);
                    cur = strs[i].charAt(index);
                }
                else {
                    cur = strs[i].charAt(index);
                    if (cur != pre) {
                        check++;
                        break;
                    }
                }
            }
            if (cur == '\0') break;
            if (check == 0) {
                index++;
                res += cur;
            }
            else break;
        }

        return res;
    }
}