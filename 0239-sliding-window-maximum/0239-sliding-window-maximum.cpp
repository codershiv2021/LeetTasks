class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int n = nums.size();
        int i =0; int j=1; dq.push_back(nums[0]);
        //1 3 7 2-1 -2 -3 4 5 
        //-1 2 3 -2 4 5 
        //3 5
        vector<int>ans;
        while (j<=n){
            if (j<n&&j-i<k){
                while(!dq.empty() && dq.back()<nums[j]){
                    dq.pop_back();
                }
            }
            else{
                ans.push_back(dq.front());
                if (j==n){
                    break;
                }
                while(!dq.empty() && dq.back()<nums[j]){
                    dq.pop_back();
                }
                if (!dq.empty() && dq.front()==nums[i]){
                    dq.pop_front();
                }
                i++;
            }
            dq.push_back(nums[j]);
            j++;
        }

        return ans;
    }
};