class Solution {
public:
    bool isValid(string s) {
        stack<char>sq;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            sq.push(s[i]);
            else{
                if (sq.empty()) {
                return false;  
            }
                if((s[i]==')'&&sq.top()!='(')||(s[i]==']'&&sq.top()!='[')||(s[i]=='}'&&sq.top()!='{'))
                    return false;
                sq.pop();
            }
            
            }
        return (sq.empty());
    }
};