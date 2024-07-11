class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>maxi(n+1,0); int temp = 0;
        for(int i=n-1;i>=0;i--){
            maxi[i]= temp;
            temp= max(temp,height[i]);
        }
        temp = 0; int ans = 0;
        for (int i=0; i<n; i++){
            int ind_height = min(temp,maxi[i]);
            int toadd= max(0,ind_height-height[i]);
            temp = max(temp,height[i]);
            ans+= toadd;

        }
        return ans;


    }
};