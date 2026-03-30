class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // algorithm
        // two pointer
        // i(first) and j(last)
        // add i and j -> is it larger than target ?
                                //->j--
                    // -> is this smaller than target ?
                                // i++;
        int i=0;
        int j=numbers.size()-1;
        
        while(i<j){
            if(numbers[i] + numbers[j] == target){
                return {i+1, j+1};
            }
            if(numbers[i] + numbers[j] > target){
                j--;
            }
            if(numbers[i] + numbers[j] < target){
                i++;
            }
        }
        return {};
    }
};
