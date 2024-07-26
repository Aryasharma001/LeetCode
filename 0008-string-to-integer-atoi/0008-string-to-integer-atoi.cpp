class Solution {
public:
    int myAtoi(string s) {
        unordered_map<char,int>digits={
        {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3},
        {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
        {'8', 8}, {'9', 9}
       };
        int n = s.size();
        int i = 0;
        long long ans=0;
        int sign = 1;
        while(i<n && s[i]==' ')
            i++;
        if (i == n) return 0;
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while(i<n && digits.find(s[i])!=digits.end()){
            ans=ans*10 + digits[s[i]];
            if (ans * sign > INT_MAX) return INT_MAX;
            if (ans * sign < INT_MIN) return INT_MIN;
            i++;
        }
        return int(ans*sign);
      
        
    }
};