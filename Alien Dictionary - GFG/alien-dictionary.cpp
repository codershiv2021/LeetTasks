//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:

    string findOrder(string dict[], int N, int K) {
    unordered_map<char,vector<char> >adj;
    unordered_map<char,int>ind;
        for (int i=0; i<(N-1); i++){
            string s= dict[i];
            string t= dict[i+1];
            for (int m=0; m<min(s.size(),t.size()); m++){
                if (s[m]!=t[m]){
                    adj[s[m]].push_back(t[m]);
                    ind[s[m]]= ind[s[m]];
                    ind[t[m]]++;
                    break;
                }
            }
            
        }
        
        //adj //ind
        queue<char>q; int cnt=0;
        for (char i='a'; i<='z'; i++){
            if (ind.find(i)!=ind.end() && ind[i]==0){
                q.push(i);
            }
        }
    
        
        string stp;
        
        while (!q.empty()){
            char fr= q.front();
            stp.push_back(fr);
            q.pop();
            for (auto j: adj[fr]){
                ind[j]--;
                if (ind[j]==0){
                    q.push(j);
                }
            }
        }
        return stp;
        
        
        
        
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends