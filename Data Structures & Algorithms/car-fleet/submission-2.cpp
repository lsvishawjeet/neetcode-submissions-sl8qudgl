class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // sort on the basis of position and time it take
        vector<pair<int,float>> sortedPos; // {pos, time}
        stack<float> time; //store time only
        for(int i=0; i<position.size(); i++){
            int pos = position[i];
            float time = float(target-pos)/speed[i];
            cout<<time;
            sortedPos.push_back({pos, time});
        }

        sort(sortedPos.begin(), sortedPos.end());

        for(int i=sortedPos.size()-1; i>=0; i--){
            if(!time.empty()){
                auto [p, t] = sortedPos[i];
                if(time.top() >= t){
                    float topTime = time.top();
                    time.pop();
                    time.push(max(topTime, t));
                } else{
                    time.push(t);
                }
            } else{
                time.push(sortedPos[i].second);
            }
        }
        return time.size();
    }
};
