#User function Template for python3

class Solution:
    def printClosest (self,arr, brr, n, m, x) : 
        yrr=[]
        ab=10000000
        i=0
        j=len(brr)-1
        a=0
        b=0
        while(i<len(arr) and j>=0):
            sum=arr[i]+brr[j]
            if(sum>x):
                if(abs(sum-x)<ab):
                    a=arr[i]
                    b=brr[j]
                    ab=abs(sum-x)
                j=j-1
            elif(sum==x):
                a=arr[i]
                b=brr[j]
                break
            else:
                if(abs(sum-x)<ab):
                    a=arr[i]
                    b=brr[j]
                    ab=abs(sum-x)
                i=i+1
        yrr.append(a)
        yrr.append(b)
        return yrr


#{ 
 # Driver Code Starts
#Initial Template for Python 3

for _ in range(0,int(input())):
    n, m = map(int, input().split())
    arr = list(map(int, input().strip().split()))
    brr = list(map(int, input().strip().split()))
    x = int(input())
    ob = Solution()
    ans = ob.printClosest(arr, brr, n, m, x)
    print(abs(ans[0]+ans[1] - x))
# } Driver Code Ends