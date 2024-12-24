// Problem link: https://codeforces.com/contest/1744/problem/B



#include<bits/stdc++.h>
using namespace std;
#define ll long long

void evenOddIncrements()
{
    ll n,q;
    cin>>n>>q;
    vector<ll> arr;
    ll oddSum = 0;
    ll evenSum =0;
    ll even =0; 
    ll odd =0;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin>>x;
        if(x&1) 
        {
            oddSum+=x;
            odd++;
        }
        else 
        {
            evenSum+=x;
            even++;
        }
        arr.push_back(x);
    }
   vector<ll> ans;
        
       for(int i=0; i<q; i++)
       {
            ll type, val;
            cin>>type>>val;
            // if Even Type
            if(type==0)
            {
                if(val&1)
                {
                    ll sum = even*val;
                    sum = sum+evenSum+oddSum;
                    
                    oddSum = sum;
                    evenSum =0;
                    odd = odd+even;
                    even =0;
                    ans.push_back(sum);
                    //cout<<sum<<endl;

                }

                else
                {
                    ll sum = even*val;
                    sum = sum+evenSum;
                    evenSum = sum;
                    sum+=oddSum;
                    ans.push_back(sum);
                    //cout<<sum<<endl;
                }
            }

            // Odd Type
            
            else
            {
                if(val&1)
                {
                    ll sum = odd*val;
                    sum = sum+evenSum+oddSum;
                    even =odd+even;
                    
                    evenSum =sum;
                    oddSum = 0;
                    odd = 0;
                    ans.push_back(sum);
                    //cout<<sum<<endl;

                }

                else
                {
                    ll sum = odd*val;
                    sum = sum+oddSum;
                    oddSum = sum;
                    sum+=evenSum;
                    ans.push_back(sum);
                    //cout<<sum<<endl;
                }
            }
       } 
       for(auto it: ans) cout<<it<<endl;
}
int main()
{
    int t;
    cin>>t;
   while(t--) evenOddIncrements();
}