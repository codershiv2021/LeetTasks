class Solution {
public:
    vector<vector<string>>ans;
    bool ispal(string st){
        int n = st.size();
        bool check= 1;
        for (int i=0; i<n/2; i++){
            if (st[i]!=st[n-i-1]){
                check = 0;
            }
        }
        return check;
    }
    void T(int ind,string s,vector<string>&v){
        int n = s.size();
        if (ind==n){
            ans.push_back(v);
            return;
        }
        string st;
        for (int i= ind; i<n; i++){
            st.push_back(s[i]);
            if (ispal(st)){
                v.push_back(st);
                T(i+1,s,v);
                v.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        vector<string>v;
        T(0,s,v);
        return ans;
    }
};