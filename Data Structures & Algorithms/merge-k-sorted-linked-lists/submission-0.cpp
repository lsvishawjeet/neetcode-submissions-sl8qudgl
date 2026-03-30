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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // algorithm:
        // we iterate through each list and track the min value
        // add min node address to our new address and move the min forward
        ListNode* sol = new ListNode(0);
        ListNode* curr = sol;

        while(true){
            int min = -1;
            for(int i=0; i<lists.size(); i++){
                if(!lists[i]){
                    continue;
                }
                if(min==-1  || lists[min]->val > lists[i]->val){
                    min = i;
                }
            }
            if(min == -1) break;
            curr->next = lists[min];
            lists[min] = lists[min]->next;
            curr = curr->next;
        }
        return sol->next;
    }
};
