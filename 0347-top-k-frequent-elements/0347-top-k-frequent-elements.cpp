class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for (int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        //11 222 3 444
        //1->2 2-->3
        vector<vector<int>>v(n+1);
        for (auto i: mp){
            v[i.second].push_back(i.first);
        }
        vector<int>ans;
        for (int i=n; i>=0; i--){
            int sz= v[i].size();
            for (int j=0; j<sz; j++){
                ans.push_back(v[i][j]);
                if (ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;
        //order - O(n) worst v[0] has all elements 
    }
};