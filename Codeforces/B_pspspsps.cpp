
#include<bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--){


        int n;
    cin>>n;
    string s;
    cin>>s;
    int P=0,S=0,D=0;
    for(int i=0; i<n; i++){
        if(s[i]=='s') S++;
        else if (s[i]=='.') D++;
        else P++;
    }
    if(S==n or P==n or D==n or P==0 or S==0 ){
        cout<<"YES"<<endl;
    }
    else if((S==1 and s[0]=='s') or (P==1 and s[n-1]=='p')){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    }
}