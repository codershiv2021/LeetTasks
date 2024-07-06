class Solution {
public:
    vector<vector<int>>ans;
    void T(int i, int k, int n, vector<int>&v){
        if (k==0 && n==0){
            ans.push_back(v);
            return;
        }
        if (k==0){
            return;
        }
        for (int j=i; j<10; j++){
            if (n>=j){
                v.push_back(j);
                T(j+1,k-1,n-j,v);
                v.pop_back();
            }
        }
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        T(1,k,n,v);
        return ans;
    }
};