class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        for (int i=0; i<n; i++){
            for (int j=0; j<=i; j++){
                if (i==j){
                    dp[i][j]=1;
                }
                else if (i-j==1){
                    if (s[i]==s[j]){
                        dp[i][j]=1;
                    }
                    
                }
                else if (s[i]==s[j]){
                        dp[i][j]= dp[i-1][j+1];
                    
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        int maxi = 1; int st= 0; int end= 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<=i; j++){
                if (dp[i][j]==1 && i-j+1>maxi){
                    maxi = max(maxi,i-j+1);
                    st = j; end = i; 
                }
            }
        }
        string stp= s;
        return stp.substr(st, end-st+1);
    }
};