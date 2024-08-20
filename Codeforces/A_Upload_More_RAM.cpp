#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; 
    cin>>t;
    while(t--){
    	int n,k;
        cin >> n >> k;
        int ans = (n - 1) * k;
        ans++;
        cout << ans << endl;
    }
}