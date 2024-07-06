class Solution {
public:
    bool ans = 0;

    void T(int ind, int i, int j,int m , int n, vector<vector<char>>& board, string word,vector<vector<bool>>&vis){
        vector<int>row = {-1,0,0,1};
        vector<int>col = {0,-1,1,0};
        vis[i][j]= 1;
        if (ind==(word.size()-1)){
            ans = 1;
            return;
        }
        for (int it=0; it<4; it++){
            int q = i+ row[it];
            int w = j+ col[it];
if (q>=0 && w>=0 && q<m && w<n && vis[q][w]==0 && 
board[q][w]==word[ind+1]){
    if (ans){
        return;
    }
        T(ind+1,q,w,m,n,board,word,vis);
        }
        }
        vis[i][j]=0;
        return;
     }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (board[i][j]==word[0]){
                    vector<vector<bool>>vis(m+1,vector<bool>(n+1,0));
                    T(0,i,j,m,n,board,word,vis);
                }
            }
        }
          return ans;
    }
  
};