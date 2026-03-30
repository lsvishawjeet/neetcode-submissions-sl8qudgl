/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // algorithm:
        // create a unordered map ds
        // node Address as key and new node as map value
        // start from top of map, in list, check values and add that values to corresponsing node
        unordered_map<Node*, Node*> mp;
        Node* temp = head;
        while(head){
            mp[head] = new Node(head->val);
            head = head->next;
        }
        for(auto &it : mp){
            Node* original = it.first;
            Node* newNode = it.second;
            newNode->next = original->next ? mp[original->next] : nullptr;
            newNode->random = original->random ? mp[original->random] : nullptr;
        }
        return mp[temp];
    }
};
