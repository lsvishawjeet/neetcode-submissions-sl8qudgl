class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        // create a bucket
        vector<vector<int>> bucket(nums.size()+1);

        for(auto &it : mp){
            bucket[it.second].push_back(it.first);
        }

        vector<int> sol;
        for(int i=nums.size(); i>=0 && sol.size()<k; i--){
            for(int x : bucket[i]){
                sol.push_back(x);
                if(sol.size()>=k) break;
            }
        }
        return sol;
    }
};
