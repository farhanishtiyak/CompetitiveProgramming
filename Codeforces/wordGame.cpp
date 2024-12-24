#include<bits/stdc++.h>
using namespace std;

void solution()
{
    unordered_set<string> p1;
    unordered_set<string> p2;
    unordered_set<string> p3;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        p1.insert(s);
    }
     for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        p2.insert(s);
    }
     for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        p3.insert(s);
    }

    int t1=0,t2=0,t3=0;

    for(auto it=p1.begin(); it!=p1.end(); it++)
    {
        int a = p2.count(*it);
        int b = p3.count(*it);

        int c = a+b;
        if(c==0) t1+=3;
        else if(c==1) t1+=1;
        else t1+=0;
    }

    for(auto it=p2.begin(); it!=p2.end(); it++)
    {
        int a = p1.count(*it);
        int b = p3.count(*it);

        int c = a+b;
        if(c==0) t2+=3;
        else if(c==1) t2+=1;
        else t2+=0;
    }

    for(auto it=p3.begin(); it!=p3.end(); it++)
    {
        int a = p1.count(*it);
        int b = p2.count(*it);

        int c = a+b;
        if(c==0) t3+=3;
        else if(c==1) t3+=1;
        else t3+=0;
    }

    cout<<t1<<" "<<t2<<" "<<t3<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--) solution();
}