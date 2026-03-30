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
    pair<ListNode*,ListNode*> reverseNode(ListNode* head, int k){
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr && k>0){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            k--;
        }   
        return {prev, curr};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* forCount = head;
        ListNode* nextTail = nullptr;
        while(forCount){
            count++;
            forCount = forCount->next;
            if(count%k == 0){
                nextTail = forCount;
            }
        }
        // we have total number of nodes
        // how many nodes will remain at last
        int totalIterations = count / k;
        ListNode* prev = nullptr; //update this one time only
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        ListNode* tailAfterReverse = curr;

        for(int i=0; i<totalIterations; i++){
            auto p = reverseNode(head, k);
            ListNode* newHead = p.first;
            if(prev == nullptr){
                prev = newHead;
            }
            tailAfterReverse->next = p.first;
            tailAfterReverse = head;
            head = p.second;
        }
        if(nextTail != nullptr){
            tailAfterReverse->next = nextTail;
        }

        return prev;
    }
};
