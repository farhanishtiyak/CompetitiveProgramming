// Problem link: https://practice.geeksforgeeks.org/problems/minimize-the-sum-of-product1525/1?page=1&category[]=Arrays&curated[]=1&sortBy=submissions

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int minValue(int a[], int b[], int n)
    {
        long long int ans=0;
        sort(a,a+n);
        sort(b,b+n,greater<int>());
        for(int i=0; i<n; i++)
        {
            long long int x = a[i]*b[i];
            ans+=x;
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
         int n, i;
         cin>>n;
         int a[n], b[n];
         for(i=0;i<n;i++)
         cin>>a[i];
         for(i=0;i<n;i++)
         cin>>b[i];
         Solution ob;
         cout<< ob.minValue(a, b, n) <<endl;
     }
	
	return 0;
}
// } Driver Code Ends