// Problem link: https://codeforces.com/problemset/problem/1030/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void EasyProblem()
{
    int n;
    cin>>n;
    bool flag = false; 
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        if(x==1) flag = true;
    }
    if(flag) cout<<"HARD"<<endl;
    else cout<<"EASY"<<endl;

}
int main()
{
    EasyProblem();
}