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
        // example breakdown algop
        // [0, 1, 2, 3, 4, 5, 6]
        // new list = list;
        // list->0;
        // list->0->6->1->5->2
        // use two pointers slow and fast
        // once fast hit end (null pointer) -> we reached at center
        // reverse the list after the center
        // we already have start node
        // now inseart the new elements (elements after half) between

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        // lets reverse the second half of node
        ListNode* curr = slow->next;
        ListNode* prev = nullptr;
        slow->next = nullptr;
        while(curr!=nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // now merge these lists
        ListNode* l1 = head;
        ListNode* l2 = prev;
        while(l2!=nullptr){
            ListNode* l1Next = l1->next;
            ListNode* l2Next = l2->next;
            l1->next = l2;
            l2->next = l1Next;
            l1 = l1Next;
            l2 = l2Next;
        }
    }
};
