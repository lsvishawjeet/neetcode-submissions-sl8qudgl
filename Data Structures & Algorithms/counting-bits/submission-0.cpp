class Solution {
public:
    vector<int> countBits(int n) {
        // we need to find number of 1s in 0 to n
        /*
            to count number of n's of single number:

        */
        vector<int> res(n + 1);
        for(int i=0; i<=n; i++){
            for(int j=0; j<32; j++){
                if(i&(1<<j)){
                    res[i]++;
                }
            }
        }
        return res;
    }
};
