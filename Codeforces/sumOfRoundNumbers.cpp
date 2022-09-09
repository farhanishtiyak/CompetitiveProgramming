// Problem Link: https://codeforces.com/contest/1352/problem/A

// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n;
//         vector<int>arr;
//         int i=0;
//         while(n)
//         {
//             int r = n%10;
//             int ans =1;
//             for(int j=1; j<=i; j++)
//             {
//                 ans =ans*10;
//             }
//             ans*=r;
//             if(ans>0) arr.push_back(ans);
//             n/=10;
//             i++;
//         }
//         cout<<arr.size()<<endl;
//         for(auto &val:arr)
//         {
//             cout<<val<<" ";
//         }
//         cout<<endl;
//     }
// }

//                         Using Pre computation technique

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>>res;
       
    for(int i=1; i<=10000; i++)
    {
        int n =i;
        vector<int>arr;
        int k=0;
        while(n)
        {
            int r = n%10;
            int ans =1;
            for(int j=1; j<=k; j++)
            {
                ans =ans*10;
            }
            ans*=r;
            if(ans>0) arr.push_back(ans);
            n/=10;
            k++;
        }
        res.push_back(arr);
    }

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<res[n-1].size()<<endl;
        for(auto &val:res[n-1])
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
}