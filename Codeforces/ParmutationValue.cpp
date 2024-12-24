// Problem link: https://codeforces.com/contest/1743/problem/B


#include<bits/stdc++.h>
using namespace std;
#define ll long long

void parmutationValue()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        arr.push_back(i+1);
    }
    cout<<1<<" ";
    for(int i=0; i<n; i++)
    {
        if(arr[i]==1 or arr[i]==2) continue;
        else cout<<arr[i]<<" ";
    }
    cout<<2<<endl;

}
int main()
{
    int t=1;
    cin>>t;
   while(t--)  parmutationValue();
}