import java.util.*;

class Solution2 {
    public static List<List<Integer>> groupAnagrams() {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        ArrayList<Integer> line = new ArrayList<Integer>();
        line.add(9);
        line.add(10);
        line.add(11);
        res.add(line);

        List<Integer> line2 = new ArrayList<Integer>();
        line2.add(1);
        line2.add(2);
        res.add(line2);

        return res;
    }

    public static void main(String[] args) {
        System.out.println(groupAnagrams());
    }
}