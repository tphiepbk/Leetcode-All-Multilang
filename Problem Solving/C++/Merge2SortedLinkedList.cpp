#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1 == NULL && l2 == NULL) return NULL;
        ListNode* walker2 = l2;
        ListNode* new_list = l1;
        ListNode* preWalkerNew = new_list;
        ListNode* walkerNew = preWalkerNew->next;

        while (walker2 != NULL) {

            int insertVal = walker2->val;
            ListNode* new_node = new ListNode(insertVal);

            if (walkerNew == NULL && insertVal >= preWalkerNew->val) {

                preWalkerNew->next = new_node;
                walkerNew = new_node;

                walker2 = walker2->next;
            }
            else {
                if (insertVal < preWalkerNew->val) {
                    new_node->val = preWalkerNew->val;
                    preWalkerNew->val = insertVal;
                    new_node->next = walkerNew;
                    preWalkerNew->next = new_node;
                    preWalkerNew = new_node;                    

                    walker2 = walker2->next;
                }
                else if (insertVal >= preWalkerNew->val && insertVal < walkerNew->val) {
                    new_node->next = walkerNew;
                    preWalkerNew->next = new_node;
                    preWalkerNew = new_node;

                    walker2 = walker2->next;
                }

                else {
                    preWalkerNew = preWalkerNew->next;
                    walkerNew = walkerNew->next;
                }
            }
        }
        return new_list;
    }

int main() {
    ListNode* l1 = new ListNode(-2);
    l1->next = new ListNode(5);


    ListNode* l2 = new ListNode(-9);
    l2->next = new ListNode(-6);
    l2->next->next = new ListNode(-3);
    l2->next->next->next = new ListNode(-1);
    l2->next->next->next->next = new ListNode(1);
    l2->next->next->next->next->next = new ListNode(6);

    ListNode* new_list = mergeTwoLists(l1,l2);
    ListNode* walker = new_list;
    while (walker != NULL) {
        cout << walker->val << " ";
        walker = walker->next;
    }
}