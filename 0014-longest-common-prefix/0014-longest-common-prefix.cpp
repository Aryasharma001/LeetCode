class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) {
            return "";  // Handle the case of an empty input.
        }
        if(n==1){
            return strs[0];
        }
        string s = strs[0];
        string ans = "";
        
        for (int i = 1; i < strs.size(); i++) {
            ans="";
            for (int j = 0; j < strs[i].size() && j < s.size(); j++) {
                if (strs[i][j] == s[j]) {
                    ans += strs[i][j];
                } else {
                    break;  // Exit the loop on the first character mismatch.
                }
            }
            s=ans;
        }
        
        return ans;
    }
};
