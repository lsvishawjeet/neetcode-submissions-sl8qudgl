class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(auto stone : stones){
            pq.push(stone);
        }

        // pick top two elements
        while(true){
            int greatest;
            int secondGreatest;
            if(pq.size()>=2){
                greatest = pq.top();
                pq.pop();
                secondGreatest = pq.top();
                pq.pop();
                int newElement = greatest - secondGreatest;
                if(newElement == 0){
                    continue;
                } else{
                    pq.push(newElement);
                }
            } else{
                break;
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};