class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        int words=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                ans++;
            }
            else{
                ans=0;
            }
            if(ans!=0)
                words=ans;
        }
        return words;
        
    }
};