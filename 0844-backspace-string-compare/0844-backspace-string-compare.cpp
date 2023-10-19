class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        stack<char>s2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#' && !s1.empty())
                s1.pop();
            if(s[i]!='#')
                s1.push(s[i]);
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#' && !s2.empty())
                s2.pop();
            if(t[i]!='#')
                s2.push(t[i]);
        }
        if(s1!=s2)
            return false;
        else
            return true;
    }
};