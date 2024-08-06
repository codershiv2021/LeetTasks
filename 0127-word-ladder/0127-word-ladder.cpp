class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool>mp;
        unordered_map<string,bool>vis;
        for (auto i: wordList){
            mp[i]=1;
        }
        if (mp[endWord]==0){
            return 0;
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        vis[beginWord]=1;
        while(!q.empty()){
            string Top = q.front().first;
            int num = q.front().second;
            if (Top==endWord){
                return num;
            }
            q.pop();
            for (int i=0; i<Top.size(); i++){
                for (char j='a'; j<='z'; j++){
                    string temp = Top;
                    temp[i]=j;
                    if (mp[temp] && !vis[temp]){
                        vis[temp]=1;
                        q.push({temp,num+1});
                    }
                }
            }
        }
        return 0;
    }
};