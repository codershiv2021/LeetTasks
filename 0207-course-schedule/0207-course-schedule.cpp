class Solution {
public:
    bool flag = 1;
    void T(int i, int par, unordered_map<int,bool>&vis,unordered_map<int,bool>&dfs_vis,
    unordered_map<int,vector<int>>&adj){
        vis[i]=1;
        dfs_vis[i]=1;
        for (auto k:adj[i]){
            if (!vis[k]){
                T(k,i,vis,dfs_vis,adj);
            }
            
            else{
                if (dfs_vis[k]){
                    flag = 0;
                }
            }
        }
        dfs_vis[i]=0;
        return;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,bool>vis;
        unordered_map<int,bool>dfs_vis;
        for (auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        for (int i=0; i<numCourses; i++){
            if (!vis[i]){
                T(i,-1,vis,dfs_vis,adj);
            }
        }
        return flag;
    }
};