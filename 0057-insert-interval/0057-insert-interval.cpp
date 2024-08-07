class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        if (n==0){
            return intervals;
        }
        vector<vector<int>>v;
        int a= intervals[0][0];
        int b = intervals[0][1];
        for (int i=1; i<n; i++){
            if (b>=intervals[i][0]){
                b = max(b, intervals[i][1]);
            }
            else{
                v.push_back({a,b});
                a = intervals[i][0];
                b = intervals[i][1];
            }
        }
        v.push_back({a,b});
        return v;
    }
};