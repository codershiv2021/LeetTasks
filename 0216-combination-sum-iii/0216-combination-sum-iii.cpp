class Solution {
public:
    vector<vector<int>>v;
void T(vector<int>&numbers, int k, int sum, int n, vector<int>&temp){
        //k<0 - reurn .. 
        if (k<0){
            return;
        }
        if (n==0){
            if (sum==0 && k==0){
                v.push_back(temp);
            }
            return;
        }
        if (numbers[n-1]<=sum){
            temp.push_back(numbers[n-1]);
            T(numbers,k-1,sum-numbers[n-1],n-1,temp);
            temp.pop_back();
            T(numbers,k,sum,n-1,temp);
        }
        else{
            T(numbers,k,sum,n-1,temp);
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>numbers;
        for (int i=1; i<=9; i++){
            numbers.push_back(i);
        }
        vector<int>temp;
        T(numbers,k,n,9,temp);
        return v;
    }
};