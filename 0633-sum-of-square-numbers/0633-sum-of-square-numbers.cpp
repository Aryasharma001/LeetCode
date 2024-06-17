class Solution {
public:
    bool judgeSquareSum(int c) {
        long high=sqrt(c);
        long low=0;
        while(low<=high){
            if((low*low)+(high*high)==c)
                return true;
            else if((low*low)+(high*high)<c){
                low++;
            }
            else
                high--;
        }
        return false;
    }
};