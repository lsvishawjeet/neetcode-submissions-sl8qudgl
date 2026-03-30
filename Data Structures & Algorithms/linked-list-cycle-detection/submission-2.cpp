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
        // take two pointer and run at 2x
        if(head == nullptr) return false;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        while(ptr1->next != nullptr && ptr2->next != nullptr && ptr2->next->next != nullptr){
            if(ptr1 == ptr2){
                return true;
            }
            if(ptr1->next != nullptr){
                ptr1 = ptr1->next;
            }
            if(ptr2->next != nullptr && ptr2->next->next != nullptr){
                ptr2 = ptr2->next->next;
            }
        }
        return false;
    }
};
