// Problem Link: https://codeforces.com/contest/1582/problem/B

#include<bits/stdc++.h>
using namespace std;

void solution()
{
    int n;
    cin>>n; 
    long long int zero =0;
    long long int one =0;
    long long int sum=0;
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        long long int x;
        cin>>x;
        sum+=x;
        if(x==1) one++;
        if(x==0) zero++;
        v.push_back(x);
    }

    long long int x = pow(2,zero);
    x-=1;
    x=(one*x)+one;
    cout<<x<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--) solution();
}




// Second Try:          Without Subsequences (Time limit Exit)
/*
#include <bits/stdc++.h>
using namespace std;
void countSecquences(int ind, int target, vector<int> &arr, unordered_map<string, int> &mp)
{
    if (ind == arr.size())
    {
        if (target == 0)
        {
            mp["ans"]++;
        }
        return;
    }

    if (arr[ind] <= target)
    {
        countSecquences(ind + 1, target - arr[ind], arr, mp);
    }
    countSecquences(ind + 1, target, arr, mp);
}

void solution()
{
    int n;
    cin >> n;
    vector<int> arr;
    int target = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        target += x;
        arr.push_back(x);
    }
    target -= 1;
    unordered_map<string, int> mp;
    countSecquences(0, target, arr, mp);
    cout << mp["ans"] << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solution();
    }
}

*/

/*

//  First Try:            With Subsequences   (Memory Limit Exit)          


#include<bits/stdc++.h>
using namespace std;
void countSecquences(int ind, int target,vector<int>&arr, vector<vector<int>>&ans, vector<int>&ds)
{
    if(ind == arr.size())
    {
        if(target==0)
        ans.push_back(ds);
        return;
    }

    if(arr[ind]<=target)
    {
        ds.push_back(arr[ind]);
        countSecquences(ind+1,target-arr[ind],arr, ans, ds);
        ds.pop_back();
    }
    countSecquences(ind+1,target,arr,ans, ds);
}

void solution()
{
    int n;
    cin>>n;
    vector<int>arr;
    int target =0;
    for(int i=0; i<n; i++)
    {
        int x ;
        cin>>x;
        target+=x;
        arr.push_back(x);
    }
    target-=1;
    vector<vector<int>> ans;
    vector<int>ds;
    countSecquences(0,target,arr,ans,ds);
    cout<<endl<<"\t\tSubsequences Are"<<endl;
    for(auto it: ans)
    {
        for(auto i:it) cout<<i<<" ";
        cout<<endl;
    }
    cout<<endl<<"total is :"<<ans.size()<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--) solution();
}

*/





