class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(),s.end(),greater<int>());
        string ans;
        char first_char=s[0];
        for(int i=1;i<s.size();i++){
            ans+=s[i];
        }
        ans+=first_char;
        return ans;
    }
};