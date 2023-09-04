//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,pair<int,int>>>mp;
        for(int i=0;i<n;i++){
            mp.push_back({end[i], {start[i], i + 1}});
        }
        sort(mp.begin(),mp.end());
        int ans=1;
        int endlimit=mp[0].first;
        for(int i=0;i<n;i++){
            int start_time=mp[i].second.first;
            if(start_time>endlimit){
                ans++;
                endlimit=mp[i].first;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends