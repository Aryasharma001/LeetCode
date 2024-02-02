class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            long long number=i;
            for(int j=i+1;j<=9;j++){
                number=number*10+j;
                if(number<=high && number>=low)
                ans.push_back(number);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};