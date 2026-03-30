class Solution {
public:
    int jump(vector<int>& nums) {
        // from index i go to i+nums[i] indexes and select index that is greeatest among all
        int steps = 0;
        int i=0;
        if(nums.size()<2) return 0;
        while(i<nums.size()){
            int jumps = nums[i];
            if(i+jumps >= nums.size()-1) return steps+1;
            int maxIndex = i+1;
            for(int j=i+1; j<= i+jumps; j++){
                if(nums[maxIndex]+maxIndex < nums[j]+j){
                    maxIndex = j;
                }
            }
            steps++;
            i = maxIndex;
        }
        return steps;
    }
};
