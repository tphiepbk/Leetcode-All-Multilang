import java.util.*;

public class MainClass {
    public static void main(String[] args) {
        /*
        week1_GroupAnagrams obj = new week1_GroupAnagrams();
        String[] strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
        System.out.println(obj.groupAnagrams(strs));

        week1_CountingElements obj2 = new week1_CountingElements();
        int[] arr = {1,2,3,0,3,4,4,4};
        System.out.println(obj2.countElements(arr));
        

        week1_Stocks obj3 = new week1_Stocks();
        int[] prices = {6,1,3,2,4,7};
        System.out.println(obj3.maxProfit(prices));
        

        week2_MiddleOfLinkedList obj = new week2_MiddleOfLinkedList();
        ListNode head = new ListNode(0);
        head.next = new ListNode(7);
        head.next.next = new ListNode(9);
        head.next.next.next = new ListNode(10);
        head.next.next.next.next = new ListNode(6);
        
        ListNode new_list = obj.middleNode(head);
        ListNode walker = new_list;
        while (walker != null) {
            System.out.print(walker.val + " ");
            walker = walker.next;
        }
        System.out.println();

        String S = "a#c", T = "b";
        week2_BackspaceStringCompare obj4 = new week2_BackspaceStringCompare();
        System.out.println(obj4.backspaceCompare(S, T));

        week2_MinStack minStack = new week2_MinStack();
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        System.out.println(minStack.getMin());
        minStack.pop();
        System.out.println(minStack.top());
        System.out.println(minStack.getMin());
        */

        week2_ContiguousArray ca = new week2_ContiguousArray();
        int[] nums = {1,0,1,1,1,1,0,0,0,0,0,0};
        int res = ca.findMaxLength(nums);
        System.out.println(res);   
    }
}