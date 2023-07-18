// Problem link: 

///==========================================================================
///
///                   Bismillah ir-Rahman ir-Rahim
///
/// ==========================================================================
///
///                    Md. Farhan Ishtiyak Sezar
///
///                    Dept. of Computer Science and Engineering
///                    Jagannath University , Bangladesh
///
///                    ID    : Md.Farhan_Ishtiyak_Sezar
/// ==========================================================================


#include <bits/stdc++.h>
using namespace std;
#define ll    long long

void HateOne()
{
    int num,num1=0,num2=0;
    cin>>num;
    while(num>=100)
    {
        string s;
        s = to_string(num);
        int n = s.size();

        for(int i=1; i<=n; i++)
        {
            if(i!=n)
            {
                num1 = num1*10+1;
                num2 = num2*10+1;
            }
            else num1 = num1*10+1; 
        }
        if(num>=num1) num = num%num1;
        else num= num%num2;
        num1=0;
        num2=0;
    }
    if(num%11==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl; 
}
int main() 
{
    int t;
    cin>>t;
    while(t--) HateOne();

}
