class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()<=1)
            return "";
        int n=palindrome.size();
        for(int i=0;i<n/2;i++){
            if(palindrome[i]==palindrome[n-i-1] && palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome.pop_back();
        palindrome+='b';
        return palindrome;
    }
};