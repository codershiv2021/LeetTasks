class Solution {
public:
    vector<vector<string>>v;
    void T(vector<string>&temp,int i, string s,
    vector<vector<bool>>dp, int n ){
        if (i>=n){
            v.push_back(temp);
            return;
        }
        for (int ind = i; ind<n; ind++){
            if (dp[i][ind]){
                string tempo = s.substr(i,ind-i+1);
                temp.push_back(tempo);
                T(temp,ind+1,s,dp,n);
                temp.pop_back();
            }

        }
        return;
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,0));
        for (int i=0; i<n; i++){
            for (int j=0; j<=i; j++){
                if (i==j){
                    dp[j][i]= 1;
                }
                else if (i-j==1 && s[i]==s[j]){
                    dp[j][i]=1;
                }
                else if (s[i]==s[j]){
                    dp[j][i]= dp[j+1][i-1];
                }
            }
        }
        vector<string>nnn;
        T(nnn,0,s,dp,n);
        return v;


    }
};