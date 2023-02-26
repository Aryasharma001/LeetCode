//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    bool k_uni(string s,int k){
        int hsh[27]={0};
        for(int i=0;i<s.size();i++){
            hsh[s[i]-'a']++;
        }
        int count=0;
        for(int i=0;i<27;i++){
            if(hsh[i]>0)
            count++;
        }
        if(count==k)
        return true;
        else
        return false;
    }
    int longestKSubstr(string s, int k) {
    // your code here
        int left = 0, right = 1;

        int current = 1;

        int res = (k == 1) ? 1 : -1;

        unordered_map<char, int> hash;

        hash[s[0]]++;

 

        while (right < s.size() && left < s.size()) {

            hash[s[right]]++;

            if (hash[s[right]] == 1) {

                current++;

            }

 

            if (current == k) {

                res = max(res, right - left + 1);

            } else if (current > k) {

                while(current > k) {

                    hash[s[left]]--;

                    if (hash[s[left]] == 0) {

                        current--;

                    }

                    left++;

                }

            }

 

            right++;

        }

 

        return res;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends