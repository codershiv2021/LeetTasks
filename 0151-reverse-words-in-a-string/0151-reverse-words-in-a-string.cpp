class Solution {
public:
    string reverseWords(string s) {
        vector<string>v; string st; s.push_back(' ');
        for (int i=0; i<s.size(); i++){
            if (s[i]==' '){
                if (st.size()>0){
                    v.push_back(st);
                }
                st = "";
            }
            else{
                st.push_back(s[i]);
            }
        }
        reverse(v.begin(),v.end());
        string stp;
        for (auto i:v){
            stp+=i;
            stp.push_back(' ');
        }
        stp.pop_back();
        return stp;
    }
};