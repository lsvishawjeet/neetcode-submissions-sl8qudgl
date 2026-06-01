class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for(auto &num: nums){
            freq[num]++;
        }
        // no find the top k elements
        priority_queue<pair<int,int>> pq;
        for(auto &el : freq){
            pq.push({el.second, el.first});
        }
        vector<int> sol;
        int i =0;
        while(i!=k){
            sol.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        return sol;
    }
};
