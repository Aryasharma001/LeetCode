class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        set<int>sequential_digits;
        vector<int>ans;
        for(int i=1;i<=9;i++){
            long long number=i;
            for(int j=i+1;j<=9;j++){
                number=number*10+j;
                if(number<=high && number>=low)
                ans.push_back(number);
                // sequential_digits.insert(number);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};