class Solution {
  public:

    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        
         int V = adj.size(); 
        vector<int> vis(V, 0);  
        vector<int> bfs;        

    
        
         vis[0] = 1;
        queue<int> q;
        q.push(0);
  
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};
