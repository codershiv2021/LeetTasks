class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        for (int i=0; i<n;i++){
            if (asteroids[i]>=0){
                st.push(i); continue;
            }
while(!st.empty() && asteroids[st.top()]>0 &&
asteroids[st.top()]<abs(asteroids[i])){
        st.pop();
            }
            if (!st.empty() && asteroids[i]+ asteroids[st.top()]==0){
                st.pop();
                continue;
            }
            if (!st.empty() && asteroids[st.top()]>abs(asteroids[i])){
                continue;
            }
            st.push(i);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(asteroids[st.top()]);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};