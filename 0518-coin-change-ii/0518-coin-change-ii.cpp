class Solution {
public:
    int T(int amount,vector<int>&coins,int n, vector<vector<int>>&dp){
        if (amount==0 && n==0){
            return 1;
        }
        if (n==0){
            return 0;
        }
        if (dp[amount][n]!=-1){
            return dp[amount][n];
        }
        if (amount>=coins[n-1]){
dp[amount][n]= T(amount-coins[n-1],coins,n,dp)+ T(amount,coins,n-1,dp);
        }
        else{
            dp[amount][n]= T(amount,coins,n-1,dp);
        }
        return dp[amount][n];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(amount+1, vector<int>(n+1,-1));
        return T(amount,coins,n,dp);
    }
};