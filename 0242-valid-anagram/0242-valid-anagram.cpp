class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size()>s.size())
            return false;
        int hsh[500]={0};
        int table[500]={0};
        for(int i=0;i<t.size();i++)
            hsh[int(t[i])]++;
        for(int i=0;i<s.size();i++)
            table[int(s[i])]++;
        for(int i=0;i<500;i++){
            if(table[i]!=hsh[i])
                return false;
        }
        return true;
    }
    
};