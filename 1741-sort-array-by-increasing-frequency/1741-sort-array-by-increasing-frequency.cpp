class Solution {
public:
    class cmp{
        public:
    bool operator()(pair<int,int>&a, pair<int,int>&b){
        if (a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }
    };

    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for (auto i: nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq; 
        for (auto i: mp){
            pq.push({i.second,i.first});
        }
        vector<int>ans;
        while(!pq.empty()){
            pair<int,int>Top= pq.top();
            int freq= Top.first;
            pq.pop();
            while(freq--){
                ans.push_back(Top.second);
            }
        }


        return ans;
    }
};