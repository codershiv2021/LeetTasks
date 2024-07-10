class Solution {
public:

//explain in interview like of heights - {1,9,8,7, 5, (4/6)} 
//now for 5, left ke 7,8,9 useless and now next ot 5 is either less or greater than 5 ... if greater tab toh 5 par ruk jayega .. but if lesser tab toh uske liye bhi 9,8,7 bhi useless so no problem in popping out 9,8,7 ... aise explain 
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n = heights.size();
        unordered_map<int,vector<int>>index;
        for (int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if (st.empty()){
                index[i].push_back(-1);
            }
            else{
                index[i].push_back(st.top());
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for (int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if (st.empty()){
                index[i].push_back(n);
            }
            else{
                index[i].push_back(st.top());
            }
            st.push(i);
        }
        int maxi = 0;
        for (int i=0; i<n; i++){
            int len = index[i][1]-index[i][0]-1;
            maxi = max(maxi,heights[i]*len);
        }
        return maxi;
    }
};