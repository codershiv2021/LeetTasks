class Solution {
public:
    vector<vector<int>>v;
    void T(int st, int end, int node,
    unordered_map<int, vector<int>>&adj, unordered_map<int,bool>&vis,
    vector<int>&temp ){
        vis[node]=1;
        temp.push_back(node);
        if (node==end){
            v.push_back(temp);
            vis[node]=0;
            temp.pop_back();
            return;
        }
        for (auto i: adj[node]){
            if (!vis[i]){
                T(st,end,i,adj, vis, temp);
            }
        }
        vis[node]=0;
        temp.pop_back();
        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size(); //total nodes
        unordered_map<int, vector<int>>adj;
        unordered_map<int,bool>vis;
        for(int i=0; i<n; i++){
            adj[i]=graph[i];
        }
        vis[0]=1;
        vector<int>item;
        T(0,n-1,0,adj,vis,item);
        return v;
    }
};