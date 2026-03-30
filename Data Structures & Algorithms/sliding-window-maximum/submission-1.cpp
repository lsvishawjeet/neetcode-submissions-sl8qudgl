class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int lastMaxIndex = 0;
        int lastMaxVal = nums[0];;
        vector<int> sol;

        for(int i=0; i<k; i++){
            if(nums[i]>lastMaxVal){
                lastMaxIndex = i;
                lastMaxVal = nums[i];
            }
        }

        int i=1;
        int j=i+k-1;

        sol.push_back(lastMaxVal);

        while(j<nums.size()){
            
            if(lastMaxIndex >= i && lastMaxIndex < j){
                if(nums[j]>=lastMaxVal){
                    lastMaxVal = nums[j];
                    lastMaxIndex = j;
                }
            } else{
                lastMaxVal = INT_MIN;
                for(int m=i; m<=j; m++){
                    if(nums[m]>lastMaxVal){
                        lastMaxIndex = m;
                        lastMaxVal = nums[m];
                    }
                }
            }
            sol.push_back(lastMaxVal);
            i++;
            j++;
        }
        return sol;
    }
};
