class Solution {
public:
    int minSteps(string s, string t) {
        int hashS[27]={0};
        int hashT[27]={0};
        int ans=0;
        for(int i=0;i<s.size();i++){
            hashS[int(s[i]-'a')]++;
        }
        for(int i=0;i<t.size();i++){
            hashT[int(t[i]-'a')]++;
        }
        for(int i=0;i<27;i++){
            if(hashS[i]-hashT[i]<0){
                continue;
            }
            else
            ans+=(hashS[i]-hashT[i]);
        }
        return ans;
    }
};