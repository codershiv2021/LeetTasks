class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
priority_queue<pair<int,pair<int,int>>,
vector<pair<int,pair<int,int>>>,
greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n+1,vector<int>(m+1,INT_MAX));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        vector<int>row= {-1,0,0,1};
        vector<int>col={0,1,-1,0};
        while(!pq.empty()){
            int Dist= pq.top().first;
            int Row= pq.top().second.first;
            int Col = pq.top().second.second;
            pq.pop();
            if (Row==n-1 && Col==m-1){
                continue;
            }
            for (int i=0; i<4; i++){
                int New_row = Row+row[i];
                int New_col = Col+col[i];
if (New_row>=0&&New_row<n&&New_col>=0&&New_col<m){
int Maxi = max(Dist,abs(heights[New_row][New_col]-heights[Row][Col]));
        if (dist[New_row][New_col]>Maxi){
            dist[New_row][New_col]= Maxi;
            pq.push({Maxi,{New_row,New_col}});
        }
}
            }
        }
        return dist[n-1][m-1];


    }
};