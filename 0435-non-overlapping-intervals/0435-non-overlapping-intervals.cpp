class Solution {
public:
    static bool cmp(vector<int>v1, vector<int>v2){
        return v1[0]<v2[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int i= intervals[0][0];
        int j = intervals[0][1];
        int cnt = 0;
        for (int ind =1 ; ind<n ; ind++){
            if (j>intervals[ind][0]){
                cnt++;
                j = min(j, intervals[ind][1]);
            }
            else{
                i= intervals[ind][0];
                j= intervals[ind][1];
            }
        }
        return cnt;

    }
};