class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,int>>pq;
        //contains tasks to be runn
        queue<pair<int,int>>q;
        //runn now put in queue to wait while cooldown
        unordered_map<char,int>mp;
        for (auto i: tasks){
            mp[i]++;
        }
        int time = 0;
        for (auto i: mp){
            pq.push({i.second,0});
        }
        while(true){
            //pq can be null

            if(pq.empty() && q.empty()){
                return time;
            }

            if (!q.empty()){
                int rem_time = time- q.front().second;
                if (rem_time>n){
                    pq.push({q.front().first,0});
                    q.pop();
                }
            }
            if (!pq.empty()){
                if(pq.top().first>1){
                    q.push({pq.top().first-1,time});
                }
                pq.pop();
            }

            time++;

        }
        return -1;
    }
};