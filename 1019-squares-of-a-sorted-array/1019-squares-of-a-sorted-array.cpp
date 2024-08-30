class Solution {
public:
    int find(int low, int high , vector<int>&nums){
        while(low<high){
            int mid = (low+high)/2;
            if (nums[mid]<0){
                low = mid+1;
            }
            else{
                high= mid;
            }
        }
        return low;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int ind = find(0, n-1, nums); bool flag=1;
        vector<int>v;
        if (nums[0]>=0){
            flag=0;
            v= nums;
            // swauar and return bc
        }
        if (nums[n-1]<=0){
            flag=0;
            v= nums;
            reverse(v.begin(),v.end());
             //reverse .. suaar
        }
        if (flag){
        reverse(nums.begin(),nums.begin()+ind);
        int st = 0; int end = ind;
        while(st<end && ind<n){
            if (abs(nums[st])<abs(nums[ind])){
                v.push_back(nums[st]);
                st++;
            }
            else{
                v.push_back(nums[ind]);
                ind++;
            }
        }
        while(st<end){
            v.push_back(nums[st]);
            st++;
        }
        while(ind<n){
            v.push_back(nums[ind]);
            ind++;
        }
        }
        for (auto &i: v){
            i= i*i;
        }
        return v;





    }
};