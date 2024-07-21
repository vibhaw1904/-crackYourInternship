private:
    void dfs(int node,vector<int>&ls,int vis[],vector<int>adj[])
    {
        vis[node]=1;
        ls.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                dfs(it,ls,vis,adj);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        int start=0;
        vector<int>ls;
        dfs(start,ls,vis,adj);
        return ls;
    }