class Solution {
public:
    int ans = 0;
    bool T(int mid, vector<int>start, int d) {
        //[0,3,6]
        // vector<int>start= Start;
int n = start.size(); int mini = INT_MAX; bool check = 1; //check kro
        for (int i=1; i<n; i++){
            if(start[i]-start[i-1]>=mid){
                mini = min(mini, start[i]-start[i-1]);
            }
            else{
                if (start[i]+d-start[i-1]<mid){
                    check = 0;
                }
                else{
                    start[i]= start[i-1]+mid;
                    mini = min(mini, start[i]-start[i-1]);
                }
            }
        }
        if (check){
            ans = mini;
        }
        return check;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());
        int n = start.size(); int high = 0;
        for (int i=1; i<n; i++){
            high= max(high, start[i]-start[i-1]);
        }
        int low = 0; high+=(d+1);  //6
        while(low<high){
            int mid = low+(high-low)/2;
            if (T(mid,start,d)){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return ans;
    }
};