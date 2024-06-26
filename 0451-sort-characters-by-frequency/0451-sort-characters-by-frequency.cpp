class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for (auto i:s){
            mp[i]++;
        }
        priority_queue<pair<int,char>>pq;
        for (auto i: mp){
            pq.push({i.second,i.first});
        }
        string st;
        while(!pq.empty()){
            int count = pq.top().first;
            char num = pq.top().second;
            while(count--){
                st.push_back(num);
            }
            pq.pop();
        }
        return st;
    }
};