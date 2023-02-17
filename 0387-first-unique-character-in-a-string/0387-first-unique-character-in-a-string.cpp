class Solution {
public:
    int firstUniqChar(string s) {
        int hsh[500]={0};
        bool flag=1;
        for(int i=0;i<s.size();i++)
            hsh[int(s[i]-'a')]++;
        vector<pair<string,int>> m(s.size());
        for(int i=0;i<s.size();++i){
            m[i].first=s[i];
            m[i].second=hsh[int(s[i]-'a')];
        }
        int ans;
        for(int i=0;i<s.size();i++){
            if(m[i].second==1){
                flag=0;
                ans=i;
                break;
        }
        }
        if(flag==1)
            return -1;
        else
            return ans;
    }
};