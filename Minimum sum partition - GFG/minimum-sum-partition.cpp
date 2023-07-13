//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    
	   
    // int minimumDifference(vector<int>& nums) {
    vector<int>nums;
    for(int i=0; i<n; i++){
        nums.push_back(arr[i]);
    }
        // int n= nums.size();
        int sum=0;
        for (int i=0; i<n; i++){
            sum+=nums[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1e9));

        for (int i=0; i<=n; i++){
            for (int j=0; j<=sum; j++){
                if (i==0){
                    dp[i][j]=0;
                }
                if (j==0){
                    dp[i][j]=1;
                }
            }
        }
        for (int i=1; i<=n; i++){
            for (int j=1; j<=sum; j++){
                if (nums[i-1]<=j){
        dp[i][j]= dp[i-1][j-nums[i-1]]||dp[i-1][j];
                }
                else{
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        int s1=0;
        for (int i=0 ;i<=sum/2; i++){
            if (dp[n][i]==1){
                s1= i;
            }
        }
        return sum-2*s1;

    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends