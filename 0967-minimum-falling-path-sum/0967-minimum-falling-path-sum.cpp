class Solution {
public:
    int T(vector<vector<int>>& matrix, int i, int j,vector<vector<int>>&dp, int n ){
        if (i==n-1){
            return matrix[i][j];
        }
        if (dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini = INT_MAX;
        for(int a = -1; a<2; a++){
            if (j+a>=0 && j+a<n){
            mini = min(mini, T(matrix, i+1,j+a, dp,n));
            }
        }
        return dp[i][j]= matrix[i][j]+ mini;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        int mini = INT_MAX;
        for (int i=0; i<n; i++){
            mini = min(mini,T(matrix,0,i,dp,n));
        }
        return mini;
    }
};