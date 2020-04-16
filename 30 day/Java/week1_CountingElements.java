import java.util.Arrays;
import java.util.ArrayList;

public class week1_CountingElements {
    public int countElements(int[] arr) {
        Arrays.sort(arr);
        ArrayList<Integer> res = new ArrayList<Integer>();
        int index1 = 0;
        int index2 = 0;    
        int size = arr.length;
        while (index2 < size) {
            if (index1 == index2) index2++;
            if (index1 >= size || index2 >= size) break;
            if (arr[index1] + 1 == arr[index2]) {
                res.add(index1);
                index1++;
            }
            else if (arr[index1] == arr[index2]) {
                index2++;
                if (index2 >= size) break;
            }
            else {
                index1++;
            }
        }
        return res.size();
    }
}