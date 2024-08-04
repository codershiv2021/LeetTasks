class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0]==1){
            return -1;
        }
        vector<vector<bool>>vis(n+1, vector<bool>(m+1,0));
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        vis[0][0]=1;
        vector<int>row = {-1,-1,-1,0,0,1,1,1};
        vector<int>col = {0,1,-1,1,-1,-1,0,1};
        while(!q.empty()){
            int dist = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            if (x==n-1 && y==m-1){
                return dist;
            }
            q.pop();
            for (int i=0; i<8; i++){
                int new_x= x+row[i];
                int new_y= y+col[i];
if (new_x>=0&&new_x<n&&new_y>=0&&new_y<m && !vis[new_x][new_y]
&& grid[new_x][new_y]==0){
        q.push({dist+1,{new_x,new_y}});
        vis[new_x][new_y]=1;
}
            }

        }
        return -1;
        
    }
};