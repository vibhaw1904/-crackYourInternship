class Solution {
    private:
    bool dfs(int node,vector<int> adj[],int vis[],int pathVis[],int check[]){
        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis,check)==true){
                   check[node]=0;
                return true; 
                }
                
            }
            else if(pathVis[it]){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathVis[V]={0};
        int check[V]={0};
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                (dfs(i,adj,vis,pathVis,check));
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};