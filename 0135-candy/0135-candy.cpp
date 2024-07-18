class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>maxi(n+1,1);
        vector<int>mini(n+1,1);
        for (int i=0; i<(n-1); i++){
            if (ratings[i]<ratings[i+1]){
                maxi[i+1]= maxi[i]+1;
            }
        }
        for (int i=n-1; i>0; i--){
            if (ratings[i-1]>ratings[i]){
                mini[i-1]= mini[i]+1;
            }
        }
        int ans = 0;
        for (int i=0; i<n; i++){
            ans+=(max(maxi[i],mini[i]));
        }
        return ans;


         
    }
};