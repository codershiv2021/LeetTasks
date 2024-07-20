class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i =0; int n = nums.size();
        int k = nums[0];
        while(i<=k){
            if (i==n-1){
                return true;
            }
            k = max(k,i+nums[i]);
            i++;
        }
        return false;
    }
};