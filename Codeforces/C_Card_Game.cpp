#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++) cin>>arr[i];

    int ans =0;
    int evenSum = 0;

    for(int i=n; i>=1; i--)
    {
        if(i&1)
        {
            if(arr[i]>=0)
            {
                ans+=arr[i];
                ans+=evenSum;
                evenSum  = 0;
                arr.resize(i);
            }
            
        }
        else
        {
            if(arr[i]<0){
                ans+=evenSum;
                evenSum =0;
                arr.resize(i);
            }
            else evenSum+=arr[i];
        }
    }

    if(arr.size()>=3)
    {
        for(int i=arr.size()-1; i>=1; i--)
        {
            if(arr[i]<0) arr.resize(i);
            else break;
        }
        // vector<int> preSum;
        // preSum.push_back(0);
        // for(int i=1; i<arr.size(); i++){
        //     if(arr[i]>0){
        //         int val = arr[i] + preSum[preSum.size()-1];
        //         preSum.push_back(val);
        //     }
        // }
        // cout<<"Presum"<<endl;
        // for(auto it: preSum) cout<<it<<" ";
        // cout<<endl;

        // int total = preSum[preSum.size()-1];
        // int maxi = 0;
        // for(int i=1; i<arr.size(); i++){
        //     int cur =0;
        //     if(arr[i]<0){
        //         int ind = i/2;
        //         if(ind<preSum.size()){
        //             cur += (total-preSum[ind]+arr[i]);
        //             maxi = max(maxi, cur);
        //         }
        //     }
        //     else{
        //         int ind = i/2;
        //         if(ind<preSum.size()){
        //             cur +=(total-preSum[ind]);
        //             maxi = max(maxi, cur);
        //         }
                
        //     }
        // }
        // ans+=maxi;

        int total =0;
        int maxi = 0;
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i]>0) total+=arr[i];
        }
        int cur =0;
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i]<0){
                maxi = max(maxi, (total-cur+arr[i]));
            }
            else{
                maxi = max(maxi, (total-cur-arr[i]));
                cur+=arr[i];
            }
        }
        ans+=maxi;
    }



    //cout<<"ans: "<< ans<<endl;
    cout<<ans<<endl;

    // for(auto it: arr) cout<<it<<" ";
    // cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
// #ifndef ONLINE_JUDGE
   // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
// #endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}