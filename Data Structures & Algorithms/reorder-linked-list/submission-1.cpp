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
    void reorderList(ListNode* head) {
        /*
            Algorithm
            find the middle of list
            reverse the second half
            take one ponter to middle and one at start
            next = start->next
            middleNext = middle->next
            start -> next = middle
            start=start->next
            start->next = next
            middle=middle->next
            do this till middle become nullptr
        */
        //find the middle el
        ListNode* mid;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        mid = slow->next;
        //reverse the list after the mid
        slow->next = nullptr;
        ListNode*prev = nullptr;
        while(mid){
            ListNode* next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }
        ListNode* newNode = head;
        // now prev is starting node
        while(prev && newNode){
            ListNode* next = newNode->next;
            newNode->next = prev;
            ListNode* prevNext = prev->next;
            prev->next = next;
            newNode = next;
            prev = prevNext;
        }
    }
};
