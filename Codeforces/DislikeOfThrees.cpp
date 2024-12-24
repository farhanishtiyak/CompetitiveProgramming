#include<bits/stdc++.h>
using namespace std;
const int n=1001;
int arr[n];
int main()
{
    int t;
    cin>>t;
    int k=1;
    for(int i=1; i<n; i++)
    {
        if(k%3==0 || (k%10)==3)
        {
            k++;
            i--;
        }
        else
        {
            arr[i]=k;
            k++;
        }
    }
    while(t--)
    {
        int x;
        cin>>x;
        cout<<arr[x]<<endl;
    }
}