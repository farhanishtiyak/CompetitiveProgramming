
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void BicycleChain()
{
    int n, maxi = INT_MIN;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int m;
    cin>>m;
    int ar[m], ans[10010];
    for(int i=0; i<m; i++) cin>>ar[i];

    for(int i=0; i<10010; i++) ans[i] =0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(ar[j]%arr[i]==0) 
            {
                int x = ar[j]/arr[i];
                maxi = max(maxi,x);
                ans[x]++;
            }
        }
    }
    cout<<ans[maxi]<<endl;
}
int main() {
  int t=1;
  while(t--) BicycleChain();
 }