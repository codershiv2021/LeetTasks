class Solution {
public:
// bool ans = false;
    bool Check(int a,string st, unordered_map<string,bool>&mp
    ,vector<int>&dp){
        int n = st.size();
        string temp;
        if (a==n){
            // ans = true;
            return true;
        }
        if (dp[a]!=-1){
            return dp[a];
        }
        dp[a]= false;

        for (int i=a; i<n; i++){
            temp.push_back(st[i]);
            if (mp[temp]==1){
            dp[a]= dp[a]||Check(i+1,st,mp,dp);
            }
        }
        return dp[a];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>mp;
        int n = s.size();
        vector<int>dp(n+1, -1);
        for (auto i: wordDict){
            mp[i]= 1;
        }
        return Check(0,s,mp,dp);
    }
};