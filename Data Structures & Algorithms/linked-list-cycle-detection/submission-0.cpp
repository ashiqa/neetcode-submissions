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
    bool hasCycle(ListNode* head) {
        ListNode* sp = head; 
        ListNode* fp = head;
        while (sp!=NULL && fp != NULL && fp->next != NULL){
            sp = sp->next;
            fp = fp->next->next;
            if (sp == fp) {
                return true;
            }
        }
        return false;
    }
};
