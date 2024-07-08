class Solution {
public:
    vector<string>ans;
    void T(int num, int n, string &st, int cnt){
        if (cnt<0 || cnt>n){return;}
        if (num==0 && cnt==0){ans.push_back(st);return;}
        if (num==0){return;}
        st.push_back('(');
        T(num-1,n,st,cnt+1);
        st.pop_back();
        st.push_back(')');
        T(num-1,n,st,cnt-1);
        st.pop_back();
        return;
    }

    vector<string> generateParenthesis(int n) {
        string st= "";
        T(2*n,n,st,0);
        //cnt - +- >=0 && <=n - end..cnt==0 ... num==0 
        return ans;
    }
};