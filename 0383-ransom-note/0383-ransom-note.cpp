class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()>magazine.size())
            return false;
        int hsh[500]={0};
        int table[500]={0};
        for(int i=0;i<ransomNote.size();i++)
            hsh[int(ransomNote[i])]++;
        for(int i=0;i<magazine.size();i++)
            table[int(magazine[i])]++;
        for(int i=0;i<500;i++){
            if(table[i]<hsh[i])
                return false;
        }
        return true;
    }
};