//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int predicate(int arr[],int i,int x){
        if(arr[i]==x)
        return 1;
        else
        return 0;
    }
    vector<int> find(int arr[], int n, int x) {
    vector<int> ans;
    sort(arr, arr + n);

    int start = 0, end = n - 1;

    // Find the first occurrence of x
    int first_occurrence = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == x) {
            first_occurrence = mid;
            end = mid - 1;  // Update end to search for the first occurrence to the left
        } else if (arr[mid] < x) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    // Find the last occurrence of x
    int last_occurrence = -1;

    start = 0;
    end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == x) {
            last_occurrence = mid;
            start = mid + 1;  // Update start to search for the last occurrence to the right
        } else if (arr[mid] < x) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    if (first_occurrence != -1) {
        ans.push_back(first_occurrence);
        ans.push_back(last_occurrence);
    } else {
        ans.push_back(-1);
        ans.push_back(-1);
    }

    return ans;
}

};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends