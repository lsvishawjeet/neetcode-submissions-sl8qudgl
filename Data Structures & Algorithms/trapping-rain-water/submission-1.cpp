class Solution {
public:
    int trap(vector<int>& height) {
        // algorithm
        // each bar can hold water:
        //          min(maxLeftBar, maxRightBar) - bar
        
        int sol = 0;

        int l = 0;
        int r = height.size()-1;

        int leftMax = height[l];
        int rightMax = height[r];

        while(l < r){
            
            if(leftMax < rightMax ){
                l++;
                leftMax = max(leftMax, height[l]);
                sol += leftMax - height[l];
            } else{
                r--;
                rightMax = max(rightMax, height[r]);
                sol += rightMax - height[r];
            }
        }


        return sol;
    }
};
