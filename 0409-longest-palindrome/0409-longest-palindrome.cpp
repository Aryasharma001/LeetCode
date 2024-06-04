class Solution {
public:
    
    int longestPalindrome(string s) {
        int ans=0;
        int odd=0;
        bool flag=0;
        vector<int>hash(256,0);
        for(int i=0;i<s.size();i++)
            hash[int(s[i])]++;
        for(auto it:hash){
            if(it==1){
                if(flag==0){
                    flag=1;
                    ans+=1;
                 }
                
                    
            }
            if(it%2!=0){
                ans+=it-1;
                odd=max(odd,it);
            }
            else
                ans+=it;
        }
        if(flag==0 && odd!=0){
            ans=ans+1;
        }
        return ans;
    }
};