#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,cnt=0;
        cin>>n;
        vector<int> vec(n);
        for(int i=0; i<n;i++){
            cin>>vec[i];
            if(vec[i]==0){
                cnt++;
            }
        }
        if(cnt==0){
            cout<<1<<endl;
            continue;
        }
        if(cnt==n){
            cout<<0<<endl;
            continue;
        }

        int y=0;
        for(int i=n-1; i>=0; i--){
            if(vec[i]==0){
                y++;
            }else{
                break;
            }
        }

        int x = 0;
        for(int i=0; i<n;i++){
            if(vec[i]==0){
                x++;
            }else{
                break;
            }
        }
        if((x+y==cnt) or x==cnt or y==cnt){
            cout<<1<<endl;
        }
        else{
            cout<<2<<endl;
        }
    }
}