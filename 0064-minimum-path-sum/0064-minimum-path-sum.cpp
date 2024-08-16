class Solution {
public:
    int T(int i, int j, int m, int n,vector<vector<int>>&dp, vector<vector<int>>& grid){
        if (i==m-1 && j==n-1){
            return grid[i][j];
        }
        if (i>=m || j>=n){
            return INT_MAX;
        }
        if (dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=grid[i][j]+ min(T(i+1,j,m,n,dp,grid),T(i,j+1,m,n,dp,grid));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n= grid[0].size();
        vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
        return T(0,0,m,n,dp,grid);
    }
};