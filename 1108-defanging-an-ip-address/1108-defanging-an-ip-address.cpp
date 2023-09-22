class Solution {
public:
    void f(string&s,int i,string &ans){
        if(i==s.size())
            return;
        if(s[i]=='.')
            ans+="[.]";
        else
            ans+=s[i];
        
        f(s,i+1,ans);
    }
    string defangIPaddr(string address) {
        string ans="";
        f(address,0,ans);
        return ans;
        
    }
};