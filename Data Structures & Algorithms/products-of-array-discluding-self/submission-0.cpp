class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // solve it using prefox and suffix
        // sol[i] = prefix[i] x suffix [i];

        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        vector<int> sol;

        prefix[0] = 1;
        suffix[nums.size()-1] = 1;

        // prefix
        for(int i=1; i<nums.size(); i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        //suffix
        for(int i=nums.size()-2; i>=0; i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        for(int i=0; i<nums.size(); i++){
            sol.push_back(prefix[i]*suffix[i]);
        }
        return sol;
    }
};
