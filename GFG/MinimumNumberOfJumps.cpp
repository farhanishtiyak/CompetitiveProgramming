#include<bits/stdc++.h>
using namespace std;

 int minJumps(int arr[], int n){
        // Your code here
        if(arr[0]==0&&n>1)
        {
            return -1;
        }
        if(n==1) 
        {
            int mini =0;
            return mini;
        }
        int i=0;
        int steps = 0;
        int sum=0;
        while(sum<n)
        {
            int t = arr[i];
            int maxi = arr[i+1];
            for(int j=i+1; j<(i+t); j++)
            {
                if(arr[j]>=maxi) 
                {
                    maxi = arr[j];
                    i=j;
                }
            }
            sum+=i;
            steps+=1;
        }
        
      return steps;  
    }
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    
    int ans = minJumps(arr,n);
    cout<<"Answer is : "<<ans<<endl;
}