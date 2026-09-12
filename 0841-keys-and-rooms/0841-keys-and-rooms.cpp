class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        vector<int> visited(rooms.size(), 0);
        visited[0]=1;
        while(!q.empty()){
            int  node=q.front();
            q.pop();

            for(int next:rooms[node]){
                if(visited[next]==0)
                {
                    visited[next] = 1;
                    q.push(next);
                }
            }
        }

        for(int i:visited)
        {
            if(i!=1)
            {
                return false;
            }
        }

        return true;
    }


};