class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five= 0; int ten = 0;
        //5 5 10 20 20
        int n = bills.size();
        for (int i=0; i<n; i++){
            if (bills[i]<10){
                five++;
            }
            else if (bills[i]==10){
                if (five==0){
                    return false;
                }
                five--;
                ten++;
            }
            else{
                if (ten>0 && five>0){
                    ten--; five--;
                }
                else if (five>2){
                    five-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};