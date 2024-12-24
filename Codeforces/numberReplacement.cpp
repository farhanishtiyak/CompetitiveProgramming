// Problem link: https://codeforces.com/contest/1744/problem/A


#include<bits/stdc++.h>
using namespace std;
#define ll long long

void numberReplacement()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    string s;
    cin>>s;
    for(int i=0; i<n; i++)
    {
        int x = arr[i];
        char ch = s[i];
        for(int j=0; j<n; j++)
        {
            if(arr[j]==x)
            {
                if(s[j]==ch) continue;
                else
                {
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }

    cout<<"YES"<<endl;
    
}
int main()
{
   int t;
   cin>>t;
   while(t--) 
   {
       numberReplacement();
   }

}