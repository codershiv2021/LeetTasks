class Solution {
public:
    static bool cmp(vector<int>&v1, vector<int>&v2){
        return v1[0]<v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>>v;
        int i = intervals[0][0];
        int j = intervals[0][1];
        for (int ind=1; ind<n; ind++){
            if(j>=intervals[ind][0]){
                j = max(j,intervals[ind][1]);
            }
            else{
                v.push_back({i,j});
                i= intervals[ind][0];
                j= intervals[ind][1];
            }
        }
        v.push_back({i,j});
        return v;
    }
};