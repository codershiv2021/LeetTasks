class Solution {
public:
    bool checkValidString(string s) {
        stack<int>st;
        stack<int>stp;
        int n = s.size();
        for (int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if (s[i]=='*'){
                stp.push(i);
            }
            else{
                if (st.empty()&& stp.empty()){
                    return false;
                }
                if (!st.empty()){
                    st.pop();
                }
                else{
                    stp.pop();
                }
            }
        }
        // ) isko done sorted ... ( isko karna hai 
        //( not empty .. * empty - false

        
        while(true){
            if(st.empty()&& stp.empty()){
                return true;
            }
            if (!st.empty() && stp.empty()){
            return false;
            }
            if (st.empty()){
                return true;
            }
            if (st.top()<stp.top()){
                st.pop(); stp.pop();
            }
            else {
                return false;
            }

        }
        return false;







    }
};