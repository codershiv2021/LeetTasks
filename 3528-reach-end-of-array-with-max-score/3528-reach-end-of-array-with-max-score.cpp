class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long n= nums.size();
        long long prev = 0;
        if (n==1){
            return 0;
        }
        long long maxi = nums[0]; long long ans = 0;
        for (long long i=1; i<n; i++){
            if (nums[i]>maxi){
                ans = ans+ (i-prev)*maxi;
                prev= i;
                maxi = nums[prev];
            }
        }
        ans = ans+(n-1-prev)*maxi;
        return ans;
    }
};