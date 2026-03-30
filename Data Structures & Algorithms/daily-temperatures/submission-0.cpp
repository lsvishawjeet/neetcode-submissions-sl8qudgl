class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st; // {temp, index}
        vector<int> vec(temperatures.size(), 0);
        
        for(int i=0; i<temperatures.size(); i++){
            int currTemp = temperatures[i];
            while(!st.empty() && currTemp > st.top().first){
                auto [temp, index] = st.top();
                st.pop();
                vec[index] = i-index; //days
            }
            st.push({currTemp, i});
        }

        return vec;
    }
};


// Input: temperatures = [30,38,30,36,35,40,28]

// Output: [1,4,1,2,1,0,0]