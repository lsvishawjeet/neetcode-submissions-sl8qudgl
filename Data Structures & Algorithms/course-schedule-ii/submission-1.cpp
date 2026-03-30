class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // order the graph
        // user topo sort for this
        // algorithm for topo sort
        // take a in vector
        // put nodes with zero incoming v to q
        // then do BFS and reduce the incoming
        vector<vector<int>> adj(numCourses);
        vector<int> incoming(numCourses, 0);
        vector<int> topo;
        for(auto course : prerequisites){
            adj[course[1]].push_back(course[0]);
            incoming[course[0]]++;
        }
        // push zero incoming in queue
        queue<int> q; // continas the index
        for(int i=0; i<numCourses; i++){
            if(incoming[i]==0){
                q.push(i);
            }
        } 
        while(!q.empty()){
            int topIndex = q.front();
            q.pop();
            for(int course : adj[topIndex]){
                incoming[course]--;
                if(incoming[course] == 0){
                    q.push(course);
                }
            }
            topo.push_back(topIndex);
        }
        return (topo.size() == numCourses) ? topo : vector<int>{} ;
    }
};
