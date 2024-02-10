class Solution {
public:
    bool isPalindrome(string temp){
        int n=temp.size();
        for(int i=0;i<n/2;i++){
            if(temp[i]!=temp[n-i-1]){
                return false;
            }
        }
        return true;
    }
    int countSubstrings(string s) {
        string temp;
        int count=0;
        for(int i=0;i<s.size();i++){
            
            temp=s[i];
            if(isPalindrome(temp)==true){
                 count++;
                // cout<<temp<<endl;
            }
            for(int j=i+1;j<s.size();j++){
                temp+=s[j];
                // cout<<temp<<" ";
                if(isPalindrome(temp)==true){
                    count++;
                    // cout<<temp<<endl;
                }
            }
        }
        return count;
    }
};