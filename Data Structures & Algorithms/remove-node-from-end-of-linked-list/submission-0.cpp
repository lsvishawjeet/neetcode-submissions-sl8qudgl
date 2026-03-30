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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int totalNodes = 0;
        //count total Nodes
        ListNode* curr = head;
        while(curr){
            curr = curr->next;
            totalNodes++;
        }
        // count the position of node to be removed
        int removePosition = totalNodes - n;
        if(removePosition == 0){
            return head->next;
        }
        curr = head;
        for(int i=0 ; i<totalNodes; i++){
            if(i+1==removePosition){
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
        }
        return head;
    }
};