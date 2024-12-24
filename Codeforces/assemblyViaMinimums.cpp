#include<bits/stdc++.h>
using namespace std;

void solution()
{
    int n;
    cin>>n;
    int total = n*(n-1)/2;
    int arr[total];
    for(int i=0; i<total; i++) cin>>arr[i];

    sort(arr,arr+n);

    int cnt = 0;
    for(int i=0; i<total; i+=(n-cnt))
    {
        cout<<arr[i]<<" ";
        cnt++;
    }
    cout<<arr[total-1]<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--) solution();
}