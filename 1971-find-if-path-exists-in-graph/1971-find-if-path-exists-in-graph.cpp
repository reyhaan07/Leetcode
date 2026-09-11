class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        q.push(source);

        vector<int> visited(n,-1);
        visited[source]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            if(node==destination) return true;
            for(int next:adj[node])
            {   
                if(visited[next]==-1){
                    q.push(next);
                    visited[next]=0;
                }
            }
        }

        return false;
    }

};