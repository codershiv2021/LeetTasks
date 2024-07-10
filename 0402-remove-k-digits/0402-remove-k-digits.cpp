class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        int n = num.size();
        if (n==k){
            return "0";
        }
        for (int i=0; i<n; i++){
            while(!st.empty() && k>0 && num[st.top()]>num[i]){
                st.pop();
                k--;
            }
            st.push(i);
        }
        string stp;
        while(!st.empty()){
            stp.push_back(num[st.top()]);
            st.pop();
        }
        while(!stp.empty() && stp.back()=='0'){
            stp.pop_back();
        }
        reverse(stp.begin(),stp.end());
        while(k--){
            if (stp.empty()){
                break;
            }
            stp.pop_back();
        }
        if (stp.empty()){
            return "0";
        }
        return stp;

    }
};