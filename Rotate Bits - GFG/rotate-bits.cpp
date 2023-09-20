//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            //code here.
            //n=n%16;
            d %= 16;
            if(d < 0){
                d += 16;
            }
            int p=pow(2,d);
            vector<int>ans={(n<<d | n>>(16-d)),(n>>d | n<<(16-d) )};
            return {((n<<d)|(n>>(16-d)))& 65535,((n>>d)|(n<<(16-d)))& 65535};
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends