#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,k;
    cin>>n>>k;
    char ch = 'a';
    string s = "";
    for (int j = 0; j < n; j++){
        ch = 'a';
        for (int i = 0; i < k; i++){
        s += ch;
        ch++;
        }
    }

        cout << s << endl;
    }
}