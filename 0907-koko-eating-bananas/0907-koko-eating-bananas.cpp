class Solution {
public:
    bool check(int mid, vector<int>&piles, int h){
        long long a =0;
        for (int i=0; i<piles.size(); i++){
            long long ab = piles[i];
            a=a+ ((ab+mid-1)/mid);
            
        }
        if (a<=(long long)h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; int high = INT_MAX;
        while(low<high){
            int mid = low+ (high-low)/2;
            if (check(mid,piles,h)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        if (check(low,piles,h)){
            return low;
        }
        return -1;
    }
};