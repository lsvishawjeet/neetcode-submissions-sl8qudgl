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

 // suppose value is 12
 // it will be written as 21
 // so i is needed and 2 is carry

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* dummyNode = new ListNode(0);
       ListNode* temp = dummyNode;
       int carry = 0;
       while(l1 || l2 || carry){
        int val = carry;
        if(l1){
            val += l1->val;
            l1 = l1->next;
        }
        if(l2){
            val += l2->val;
            l2 = l2->next;
        }
        carry = val/10;
        dummyNode->next = new ListNode(val%10);
        dummyNode = dummyNode->next;
       }
       return temp->next;
    }
};
