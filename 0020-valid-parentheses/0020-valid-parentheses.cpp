class Solution {
public:
    bool isValid(string s) {
       int n =s.length();
    unordered_map<char,char>map = {
        {'(',')'},  
        {'[',']'},  
        {'{','}'}
    };
    
    stack<int>st;
    
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
        else
        {
            if(st.empty() || map[st.top()] != s[i])
                return false;
            else
                st.pop();
        }
    }
    
    return st.empty();
    }
};