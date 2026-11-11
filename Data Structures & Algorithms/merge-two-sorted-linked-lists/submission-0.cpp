/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l3 = new ListNode(0);
        ListNode* curr = l3;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                l3 -> next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                l3 -> next = new ListNode(list2->val);
                list2 = list2->next;
            }
            l3 = l3 -> next;
        }
        if (list1 != NULL) {
            l3 -> next = list1;
        }
        if (list2 != NULL) {
            l3 -> next = list2;
        }
        return curr->next;
    }
};
