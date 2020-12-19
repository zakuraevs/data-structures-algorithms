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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* current = nullptr;
        
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val < l2->val) {
            current = l1;
            l1 = l1->next;
        } else {
            current = l2;
            l2 = l2->next;
        }

        ListNode* head = current;
        
        while(l1 && l2) {
            if(l1->val < l2->val) {
                current->next = l1;
                current = current->next;
                l1 = l1->next;
            } else {
                current->next = l2;
                current = current->next;
                l2 = l2->next;
            }
        }
        
        if(l1)
            current->next = l1;
        else
            current->next = l2;
        
        return head;
    }
};