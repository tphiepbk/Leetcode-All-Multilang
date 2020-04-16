#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

    // ListNode* middleNode(ListNode* head) {
    //     ListNode* walker = head;
    //     int size = 0;
    //     while (walker != NULL) {
    //         size++;
    //         walker = walker->next;
    //     }

    //     int pivot = size / 2;
    //     ListNode* new_list = new ListNode(-1);
    //     ListNode* walker_new = new_list;
    //     walker = head;
    //     int count = 0;
    //     while (count < size) {
    //         if (count == pivot) { 
    //             walker_new->val = walker->val;
    //         }
    //         else if (count > pivot) {
    //             ListNode* new_node = new ListNode(walker->val);
    //             walker_new->next = new_node;
    //             walker_new = walker_new->next;
    //         }
    //         walker = walker->next;
    //         count++;
    //     }

    //     return new_list;
    // }

    ////////////////////////////////////////////////

    /*
    More optimal solution
    */
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

int main() {
    ListNode* n0 = new ListNode(0);
    n0->next = new ListNode(8);
    n0->next->next = new ListNode(7);
    n0->next->next->next = new ListNode(9);
    n0->next->next->next->next = new ListNode(4);
    n0->next->next->next->next->next = new ListNode(1);
    n0->next->next->next->next->next->next = new ListNode(10);
    n0->next->next->next->next->next->next->next = new ListNode(2);
    n0->next->next->next->next->next->next->next->next = new ListNode(6);

    cout << "Linkde List : ";
    ListNode* walker = n0;
    while (walker != NULL) {
        cout << walker->val << " ";
        walker = walker->next;
    }
    cout << "\n";

    cout << "Middle of Linked List : ";
    walker = middleNode(n0);
    while (walker != NULL) {
        cout << walker->val << " ";
        walker = walker->next;
    }
    cout << "\n";
}