// Problem link: https://codeforces.com/contest/478/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void initialBet()
{
    int arr[5], sum=0;
    for(int i=0; i<5; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum%5==0 and sum!=0) cout<<(sum/5)<<endl;
    else cout<<-1<<endl;

}
int main()
{
    initialBet();
}