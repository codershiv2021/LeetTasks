class Solution {
public:
    bool rotateString(string s, string goal) {  
        int n = s.size();
        for (int i=0; i<n; i++){
            int index2 = 0; bool red= true;
            for (int j=i; j<n+i; j++){
                int index1 = j%n;
                if (s[index1]!=goal[index2]){
                    red = false;
                    break;
                }
                index2++;
            }
            if (red){
                return true;
            }
        }
        return false;
    }
};