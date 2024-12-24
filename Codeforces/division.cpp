// Problem link: https://codeforces.com/problemset/problem/1669/A


#include<bits/stdc++.h>
using namespace std;
#define ll long long

void division()
{
    
    int rating;
    cin>>rating;
    if(rating>=1900) cout<<"Division 1"<<endl;
    else if(rating >=1600 and rating <=1899) cout<<"Division 2"<<endl;
    else if(rating>=1400 and rating <=1599) cout<<"Division 3"<<endl;
    else cout<<"Division 4"<<endl;
}
int main()
{
    int t=1;
    cin>>t;
   while(t--) 
   {
        division();
   }
}