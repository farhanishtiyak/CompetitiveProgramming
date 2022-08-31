#include<bits/stdc++.h>
using namespace std;
const int N = 9000+50;

int main()
{
    vector<int>vec;
    for(int i=1000; i<=N; i++){
        string s = to_string(i);
        set<int> dist(s.begin(), s.end());
        if(dist.size()==s.size()) vec.emplace_back(i);
    }
    int n;
    cin>>n;
    for(auto it:vec)
    {
        if(it>n) 
        {
            cout<<it<<endl;
            break;
        }
    }

}