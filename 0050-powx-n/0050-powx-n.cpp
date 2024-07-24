class Solution {
public:
    double myPow(double x, int n) {
        //n - ve
        //0.66 - 
        ios_base::sync_with_stdio(0);
        long long nn = n;
        if (nn<0){
            x= 1.0/x;
            nn= -nn;
        }
        if (nn==0){
            return 1.0;
        }
        double ans = 1;
        if (x<0){
            if (nn%2==1){
            ans = -1;}
            x= -x;
        }
        while(nn>1){
            if (nn%2==0){
                x= x*x;
                nn= nn/2;
            }
            else{
                //17
                ans = ans*x;
                nn--;
            }
        }
        ans= ans*x;
        return ans;

/// 3^18 - 9^9 - 9.9^8
    }
};