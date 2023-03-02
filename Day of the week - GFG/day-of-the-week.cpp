//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string getDayOfWeek(int d, int m, int y) {
        // code here
        static int t[] = { 0, 3, 2, 5, 0, 3,
                       5, 1, 4, 6, 2, 4 };
        y -= m < 3;
        int cal= (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
        if(cal==1)
        return "Monday";
        if(cal==2)
        return "Tuesday";
        if(cal==3)
        return "Wednesday";
        if(cal==4)
        return "Thursday";
        if(cal==5)
        return "Friday";
        if(cal==6)
        return "Saturday";
        if(cal==0)
        return "Sunday";
}
        
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int d,m,y;
        
        cin>>d>>m>>y;

        Solution ob;
        cout << ob.getDayOfWeek(d,m,y) << endl;
    }
    return 0;
}
// } Driver Code Ends