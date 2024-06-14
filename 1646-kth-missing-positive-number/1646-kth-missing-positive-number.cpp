class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(); int ans = -1;
          int low =0; int high = n-1;  
          if (arr[high]-n<k){
            ans = high;
            return arr[ans]+ (k- (arr[ans]-ans-1));
             
          }
          
          while (low<high){
            int mid = low+(high-low)/2;
            if (arr[mid]-mid-1<k){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid;
            }
          }
          if (arr[0]-1>=k){
            return k;
          }
          return arr[ans]+ (k- (arr[ans]-ans-1));
    }
};