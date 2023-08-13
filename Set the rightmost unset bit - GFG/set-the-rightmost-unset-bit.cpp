//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int N)
    {
        int mask= N;
        int cnt=0;
        int flag=0;
        while (mask>0){
            
            if ((mask & 1)==0){
                flag++;
                break;
            }
            cnt++;
            mask= mask>>1;
            
        }
        if (flag==0){
            return N;
        }
        if (cnt==0){
            N= N|1;
            return N;
        }
        N= N| (1<<cnt);
        return N;
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends