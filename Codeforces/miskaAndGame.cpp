// Problem link: 

#include<bits/stdc++.h>
using namespace std;

void miskaGame()
{
    int n;
    cin>>n;
    int miska=0, chris =0;
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        if(x>y) miska++;
        else if(y>x) chris++;
        else continue;
    }
    if(miska>chris) cout<<"Miska"<<endl;
    else if(chris>miska) cout<<"Chris"<<endl;
    else cout<<"Friendship is magic!^^"<<endl;
}
int main()
{
    int t=1;
    //cin>>t;
    while(t--) miskaGame();
}