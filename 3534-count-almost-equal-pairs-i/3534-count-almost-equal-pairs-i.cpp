class Solution {
public:
    bool check(string a, string b){
        if (a.size()>b.size()){
            return check(b,a);
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        while(a.size()<b.size()){
            a.push_back('0');
        }
        int n = a.size();
        int flag = 0; int ind1=0; int ind2= 0;
        for (int i=0; i<n; i++){
            if (a[i]!=b[i]){    
                if(flag==0){
                    ind1= i;
                }
                else{
                    ind2= i;
                }
                flag++;
            }
        }
        swap(a[ind1],a[ind2]);
        if (flag>2){
            return false;
        }
        return a==b;
    }

    int countPairs(vector<int>& nums) {
        int n = nums.size(); int cnt =0;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                string a = to_string(nums[i]);
                string b = to_string(nums[j]);
                if(check(a,b)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};