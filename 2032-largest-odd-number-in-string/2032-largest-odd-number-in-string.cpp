class Solution {
public:
    string largestOddNumber(string num) {
        while (num.size()>0){
            if (num.back()%2!=0){
                break;
            }
            else{
                num.pop_back();
            }
        }
        return num;
    }
};