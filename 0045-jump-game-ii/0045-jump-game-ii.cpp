class Solution {
public:
    int jump(vector<int>& nums) {
        //if n-1 to break ...
        
        int i =0; int n = nums.size();
        if (n==1){
            return 0;
        }
        int maxi = 0; int k = nums[0];
        int ans= 1;
        while(i<(n-1)){
            maxi = max(maxi, i+nums[i]);
            if (i==k){
                k= maxi;
                ans++;
            }
            i++;
        }
        return ans;
    }
};