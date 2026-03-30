class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // traverse rows to find the exact row where the target exist
        int rowIndex = -1;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i=0; i<rows; i++){
            if(target >= matrix[i][0] && target <= matrix[i][cols-1]){
                rowIndex = i;
                break;
            }
        }
        if(rowIndex == -1){
            return false;
        }
        cout<<rowIndex;
        int l = 0;
        int r = cols-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(matrix[rowIndex][mid] == target){
                return true;
            } else if(matrix[rowIndex][mid] < target){
                l = mid+1;
            } else{
                r = mid-1;
            }
        }

        return false;
    }
};
