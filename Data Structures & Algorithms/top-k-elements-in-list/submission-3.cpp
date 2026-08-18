class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        for(int n : nums){
            freq[n]++;
        }
        priority_queue<pair<int,int>> pq; // freq, num
        for(auto &m:freq){
            pq.push({m.second, m.first});
        }
        vector<int> sol;
        while(k > 0){
            sol.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return sol;
    }
};
