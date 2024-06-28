class Solution {
public:
    int beautySum(string s) {
        int n = s.size(); int ans = 0;
        for (int i=0; i<n; i++){
            unordered_map<int,int>mp;
            for (int j=i; j<n; j++){
                mp[s[j]]++; int maxi = 0; int mini = n+1;
                for (auto k:mp){
                    maxi = max(maxi, k.second);
                    mini = min(mini, k.second);
                }
                ans += (maxi-mini);
            }
        }
        return ans;
    }
};