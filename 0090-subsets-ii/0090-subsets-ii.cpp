class Solution {
public:
    set<vector<int>>ans;
    void T(int i, int n, vector<int>&nums,vector<int>&v){
        if (i==n){
            ans.insert(v);
            return;
        }
        v.push_back(nums[i]);
        T(i+1,n,nums,v);
        v.pop_back();
        T(i+1,n,nums,v);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int>v;
        sort(nums.begin(),nums.end());
        T(0,n,nums,v);
            vector<vector<int>>pq;
            for (auto i: ans){
                pq.push_back(i);
            }

        return pq;
    }
};