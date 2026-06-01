class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for(auto &num: nums){
            freq[num]++;
        }
        // no find the top k elements
        vector<vector<int>> bucket(nums.size()+1);
        for(auto &el : freq){
            bucket[el.second].push_back(el.first);
        }
        // now we have numbers stred at freq index
        vector<int> sol;
        for(int i = bucket.size()-1; i>=0; i--){
            for(auto &n : bucket[i]){
                sol.push_back(n);
                if(sol.size() == k) return sol;
            }
        }
        return sol;
    }
};
