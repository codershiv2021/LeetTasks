class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n==1){
            return nums[0];
        }
        if (nums[0]!=nums[1]){
            return nums[0];
        }
        if (nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }
        int i = 0; int j = n-1;
        while(i<j){
            int mid = (i+j)/2;
            if (mid%2==1){
                if (nums[mid]==nums[mid-1]){
                    i = mid+1;
                }
                else{
                    j = mid;
                }
            }
            else{
                    if (nums[mid]==nums[mid+1]){
                        i = mid+1;
                    }
                    else{
                        j = mid;
                    }

            }
        }
        return nums[i];
    }
};