class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0){
            return 0;
        }
        unordered_set<char>st;
        int i =0; int j= 0;
        int maxi = 1;
        while(i<=j && j<n){
            if (st.find(s[j])==st.end()){
                st.insert(s[j]);
                j++;
                maxi = max(maxi, j-i);
            }
            else{
                //a b c a b
                //cc 
                //abba
                //abc
                st.erase(s[i]);
                i++;
            }
        }
        return maxi;
    }
};