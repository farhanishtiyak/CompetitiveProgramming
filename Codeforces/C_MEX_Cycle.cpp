#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){

        int n,x,y;
    cin>>n>>x>>y;
    vector<int> hi(n+2);
    hi[0] = n;
    hi[n+1] = 1;
    for(int i=0; i<n; i++){
        hi[i] = i;
    }

    vector<int> ans(n+1,-20);
    for(int i=1; i<=n; i++){
        if(i==1){
            ans[1] = 0;
        }
        int oo = 0, tt = 0, zz = 0;

        if(i==y){
            if(ans[hi[x]]==0){
                zz = 1;
            }
            else if(ans[hi[x]]==1){
                oo = 1;
            }
            else if(ans[hi[x]]==2){
                tt = 1;
            }
        }

        if(ans[hi[i-1]]==0){
            zz = 1;
        }
        else if(ans[hi[i-1]]==1){
            oo = 1;
        }
        else if(ans[hi[i-1]]==2){
            tt = 1;
        }


        if(ans[hi[i+1]]==0){
            zz = 1;
        }
        if(ans[hi[i+1]]==1){
            oo = 1;
        }
        if(ans[hi[i+1]]==2){
            tt = 1;
        }

        

        if(i==x){
            if(ans[hi[y]]==0){
                zz = 1;
            }
            if(ans[hi[y]]==1){
                oo = 1;
            }
            if(ans[hi[y]]==2){
                tt = 1;
            }
        }

        

        if(zz==0){
            ans[i] = 0;
        }
        else if(oo==0){
            ans[i] = 1;
        }
        else{
            ans[i] = 2;
        }
    }

    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    }

    return 0;
}