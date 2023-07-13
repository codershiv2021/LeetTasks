//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    
    
  public:
    int pr(int l, int n, int price[],vector<vector<int>>&dp){
        if (n==0){
            return 0;
        }
        if (dp[l][n]!=-1){
            return dp[l][n];
        }
        if (l>=n){
            dp[l][n]= max(price[n-1]+pr(l-n,n,price,dp), pr(l,n-1,price,dp));
        }
        else{
            dp[l][n]= pr(l,n-1,price,dp);
        }
        return dp[l][n];
    }
  
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1))    ;
        return pr(n,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends