class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // do it using topo sort
        // it is directed graph
        // use kahns algorithm (topo sort BFS)

        // algorithm for topo sort
        // first create a array of incoming nodes
        // push nodes with indegree 0 to queue
        // then do BFS and reduce the indegree what we visited
        // as we popping the elements push into the topo sort vector
        
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        // push elements into q whose indegree is 0
        queue<int> q;

        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int topEl = q.front();
            q.pop();
            for(auto it : adj[topEl]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            count++;
        }

        return count==numCourses;

    }
};
