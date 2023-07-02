//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& Arr, int N){
      vector<int>pos,neg;
      for (int i=0; i<N; i++){
          if (Arr[i]>=0){
              pos.push_back(i);
          }
          else{
              neg.push_back(i);
          }
  }
      int i=0; int j=0;
      long long sum=0;
      while (i<pos.size() && j<neg.size()){
          if (Arr[pos[i]]>= -Arr[neg[j]]){
              Arr[pos[i]]= Arr[pos[i]]+ Arr[neg[j]];
              sum= sum+ abs(Arr[neg[j]] * (pos[i]- neg[j]));
              j++;
          }
          else{
              Arr[neg[j]]= Arr[pos[i]]+ Arr[neg[j]];
              sum = sum+ Arr[pos[i]]* abs(pos[i]- neg[j]);
              i++;
          }
      }
      return sum;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends