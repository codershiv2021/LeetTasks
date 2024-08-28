class Solution {
public:
vector<vector<int>>v;
    void T(int ind,vector<int>& nums,unordered_map<int, int>&mp, int n, vector<int>&temp ){
        if (ind==n){
            v.push_back(temp);
            return;
        }
        for (auto i:mp){
            if (i.second>0){
                mp[i.first]--;
                temp.push_back(i.first);
                T(ind+1,nums,mp,n,temp);
                temp.pop_back();
                mp[i.first]++;
            }
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for (auto i: nums){
            mp[i]++;
        }
        vector<int>temp;
        T(0,nums,mp,n,temp);
        return v;
    }
};