class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>hashS(27,0);
        string ans="";
        for(int i=0;i<s.size();i++)
            hashS[int(s[i]-'a')]++;
        for(int i=0;i<order.size();i++){
            while(hashS[int(order[i]-'a')]-->0){
                ans+=order[i];
                
            }
                
        }
        for(int i=0;i<s.size();i++){
            if(hashS[int(s[i])-'a']>0)
                ans+=s[i];
                hashS[int(s[i]-'a')]--;
            
        }
        return ans;
    }
};