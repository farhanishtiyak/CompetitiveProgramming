#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int A = (n + b + c - (2 * a))/3;
        int B = (n + a + c - (2 * b))/3;
        int C = (n + b + a - (2 * c))/3;
        int x = a+A;
        int y = b+B;
        int z = c+C;
        if((A+B+C)==n && x==y && y==z) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
}