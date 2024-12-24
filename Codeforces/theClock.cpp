
#include<bits/stdc++.h>
using namespace std;
#define MOD (int) 1e9+7
#define all(a) a.begin(),a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define tc(t) int t; cin >> t; while (t--)
#define int int
#define ll long long
#define pb emplace_back
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define vi vector<int>
#define fi first
#define se second
#define endl "\n"

// Using set

void TheClock2()
{

    unordered_set<int> st;
    string s;
    int ans =0;
    cin>>s;
    int x;
    cin>>x;
    int res;
    string sub = s.substr(0,2);
    int num = stoi(sub);
    res= (num*60);
    sub = s.substr(3,2);
    num = stoi(sub);
    res+=num;
    int loop = 0;
    bool flag = true;


    do
    {
        st.insert(res);
        res+=x;
        if(res>=1440) res-=1440;
        loop+=x;
        if(loop%1440==0) flag = false;
    }while(flag);



    for(auto i=st.begin() ; i!=st.end(); i++)
    {
        int a,b;
        int x = *i;
        a = x/60;
        b = x%60;
        
        
        string first =to_string(a);
        string second =to_string(b);
        if(a<10) first="0"+first;
        if(b<10) second = "0"+second;
        if(first[0]==second[1] && first[1]==second[0]) ans++;

    }
    cout<<ans<<endl;
}

//    Using Vectors

void TheClock()

{
    vector<int> v;
    unordered_map<int,bool> mp;
    string s;
    int ans =0;
    cin>>s;
    int x;
    cin>>x;
    int res =0;
    string sub = s.substr(0,2);
    int num = stoi(sub);
    res= (num*60);
    sub = s.substr(3,2);
    num = stoi(sub);
    res+=num;
    int brk =0;
    bool flag = true;


    while(flag)
    {
        v.pb(res);
        res+=x;
        if(res>=1440) res-=1440;
        brk+=x;
        mp[res] = true;
        if((brk%1440)==0) flag = false;
    }


    for(int i=0 ; i<v.size(); i++)
    {
        int a,b;
            a = v[i]/60;
            b = v[i]%60;
        
        
        string first =to_string(a);
        string second =to_string(b);
        if(a<10) first="0"+first;
        if(b<10) second = "0"+second;
        if(first[0]==second[1] && first[1]==second[0]) ans++;

        //cout<<first<<" "<<second<<endl;
    }
    cout<<ans<<endl;
}
int main()
{
    fio;
    tc(t) TheClock();

}