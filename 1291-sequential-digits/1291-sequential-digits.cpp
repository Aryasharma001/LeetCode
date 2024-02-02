class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        set<int>sequential_digits;
        for(int i=1;i<=9;i++){
            long long number=i;
            for(int j=i+1;j<=9;j++){
                number=number*10+j;
                sequential_digits.insert(number);
            }
        }
        vector<int>ans;
        for(auto it:sequential_digits){
            if(it<=high && it>=low)
                ans.push_back(it);
        }
        return ans;
    }
};