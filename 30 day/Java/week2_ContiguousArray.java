import java.util.*;

public class week2_ContiguousArray {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> m = new HashMap<>();
        m.put(0, -1);
        int count = 0, maxLen = 0;
        for (int i = 0 ; i < nums.length ; i++) {
            count += (nums[i] == 1) ? 1 : -1;
            if (m.containsKey(count)) {
                maxLen = Math.max(maxLen, i - m.get(count));
            }
            else {
                m.put(count, i);
            }
        }
        return maxLen;
    }    
}