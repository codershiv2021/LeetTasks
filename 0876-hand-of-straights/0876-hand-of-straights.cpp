class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n%groupSize!=0){
            return false;
        }
        sort(hand.begin(),hand.end());
        unordered_map<int,int>mp;
        for (auto i: hand){
            mp[i]++;
        }
        for (auto i: hand){
            if (mp[i]>0){
                int start = i;
                int temp = groupSize;
                while(temp--){
                    if (mp[start]==0){
                        return false;
                    }
                    else{
                        mp[start]--;
                        start++;
                    }
                }
            }
        }
        return true;
    }
};