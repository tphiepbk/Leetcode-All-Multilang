import java.util.*;

public class week1_GroupAnagrams {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res = new ArrayList<List<String>>();
        HashMap<String, ArrayList<String>> m = new HashMap<String, ArrayList<String>>();

        for (String str : strs) {
            char[] c = new char[26];
            for (int i = 0 ; i < str.length() ; i++) {
                c[(int)str.charAt(i) - 97]++;
            }

            String key = new String(c);

            if (m.isEmpty() || !m.containsKey(key)) {
                ArrayList<String> content = new ArrayList<String>();
                content.add(str);
                m.put(key, content);
            }
            else if (m.containsKey(key)) {
                m.get(key).add(str);
            }
        }

        res.addAll(m.values());

        return res;
    }

}
