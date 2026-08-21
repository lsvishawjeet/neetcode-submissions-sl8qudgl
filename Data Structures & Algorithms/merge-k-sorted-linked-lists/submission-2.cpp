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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode *dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(list1 && list2){
            if(list1->val < list2->val){
                dummy->next = list1;
                list1 = list1->next;
            } else{
                dummy->next = list2;
                list2 = list2->next;
            }
            dummy = dummy->next;
        }
        if(!list1){
            dummy->next = list2;
        } else{
            dummy->next = list1;
        }
        return temp->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int k = lists.size();
        while(k>1){
            int newSize = 0;
            for(int i=0; i<k; i+=2){
                if(i+1 < k){
                    lists[newSize] = mergeTwoLists(lists[i], lists[i+1]);
                } else{
                    lists[newSize] = lists[i];
                }
                newSize++;
            }
            k = newSize;
        }
        return lists[0];
    }
};
