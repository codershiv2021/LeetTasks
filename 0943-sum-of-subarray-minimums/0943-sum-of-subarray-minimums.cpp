class Solution {
public:
    const int mod= 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        unordered_map<int,vector<int>>ind;
        for (int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if (st.empty()){
                ind[i].push_back(-1);
            }
            else{
                ind[i].push_back(st.top());
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for (int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if (st.empty()){
                ind[i].push_back(n);
            }
            else{
                ind[i].push_back(st.top());
            }
            st.push(i);
        }
        int amp=0;
        for (int i=0; i<n; i++){
            long long toadd= ((i-ind[i][0])%mod)*((ind[i][1]-i)%mod);
            toadd= toadd%mod;
            toadd= toadd*(arr[i]%mod);
            toadd= toadd%mod;
            amp= (amp+toadd)%mod;
        }
        return amp%mod;
    }
};