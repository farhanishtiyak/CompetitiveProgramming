#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>ans;
// Pre-computation

void miniVariedNum()
{
     for(int k=1; k<46; k++)
    {
        vector<int>st;
        int x = k;
         while(x!=0)
        {
            for(int i=9; i>=1; i--)
            {
                if(x>=i) 
                {
                    st.push_back(i);
                    x-=i;
                }
            }
        }
        sort(st.begin(),st.end());
        ans.push_back(st);
    }

}

int main()
{   
    miniVariedNum();

    int t;
    cin>>t;
    
    while(t--)
    {
        int x;
        cin>>x;
        for(auto it:ans[x-1]) cout<<it;
        cout<<endl;
    }
}