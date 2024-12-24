// Problem Link: https://codeforces.com/problemset/problem/1520/A

#include<bits/stdc++.h>
using namespace std;

void doNotBeDestracted()
{
    int n;
    cin>>n; 
    string s;
    cin>>s;
    unordered_map<char,int> mp;
    bool flag = true;

    for(int i=0; i<n; i++) mp[s[i]]++;

    for(int i=0; i<n;)
    {
        char ch = s[i];
        int num = mp[ch];

        while(num--)
        {
            if(s[i]!=ch) 
            {
                flag = false; 
                break;
            }
            else i++;
        }
        
        if(!flag) break;
    }

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;    

}

int main()
{
    int t;
    cin>>t;
    while(t--) doNotBeDestracted();
}