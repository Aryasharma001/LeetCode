class Solution {
public:
    int maximumSwap(int num) {
        vector<int>digits;
        vector<int>unsorted_digit;
        int index_max=0;
        int index_min=0;
        bool flag=0;
        int i=0;
        while(num!=0){
            int a=num%10;
            digits.push_back(a);
            num=num/10;
            i++;
        }
        reverse(digits.begin(),digits.end());
        unsorted_digit=digits;
        sort(digits.begin(),digits.end(),greater<int>());
        for(int i=0;i<digits.size();i++){
            if(flag==0){
                if(digits[i]>unsorted_digit[i]){
                    index_max=i;
                    flag=1;
                }
                    
            }
            else{
                if(unsorted_digit[i]==digits[index_max])
                    index_min=i;
            }
        }
        swap(unsorted_digit[index_max],unsorted_digit[index_min]);
        int res=digits[0];
        for(int i=1;i<unsorted_digit.size();i++){
            res=res*10+unsorted_digit[i];
        }
        return res;
        
    }
};