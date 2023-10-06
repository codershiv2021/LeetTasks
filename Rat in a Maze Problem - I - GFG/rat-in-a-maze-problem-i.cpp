//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<char>dir={'U','L','D','R'};
    vector<int>row={-1,0,1,0};
    vector<int>col={0,-1,0,1};
    vector<string>ans;
    void dfs(int i,int j,int a, int b,vector<vector<int>> &m,vector<vector<bool>>&vis,string &stp ){
        vis[i][j]=1;
        if (i==a&&j==b){
            ans.push_back(stp);
            vis[i][j]=0;
            return;}
        for (int p=0; p<4; p++){
            int new_i= i+row[p];
            int new_j= j+col[p];
if (new_i>=0&&new_j>=0&&new_i<(a+1)&&new_j<(a+1)&& !vis[new_i][new_j]&&m[new_i][new_j]==1){
    stp.push_back(dir[p]);
    dfs(new_i,new_j,a,b,m,vis,stp);
    stp.pop_back();
}
        }
        vis[i][j]=0;
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        if (m[0][0]==0||m[n-1][n-1]==0){
            return {"-1"};
        }
        string stp="";
        dfs(0,0,n-1,n-1,m,vis,stp);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends