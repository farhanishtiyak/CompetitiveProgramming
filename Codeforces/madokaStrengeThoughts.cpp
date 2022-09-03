// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e8+2;
// long int arr[N];
// void solution()
// {
//     int n; 
//     cin>>n;
//     int ans =0;
//     for(int i=1; i<=n; i++)
//     {
//         for(int j=i; j<=n; j++)
//         {
//             int gcd = __gcd(i,j);
//             int lcm = (i*j)/gcd;
//             int x = lcm/gcd;
//             if(x<=3) 
//             {
//                 if(i==j) ans++;
//                 else ans+=2;
                
//             }
//         }
//     }
//     cout<<"ans is : "<<ans<<endl;
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--) solution();
// }




// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e8+1;
// long int arr[N];
// void solution()
// {
//     int n =10; 
//     //cin>>n;
    
//     for(int i=1; i<=10000; i++)
//     {
//         int ans =0;
//         for(int j=1; j<=i; j++)
//         {
//             int gcd = __gcd(i,j);
//             int lcm = (i*j)/gcd;
//             int x = lcm/gcd;
//             if(x<=3) 
//             {
//                 if(i==j) ans++;
//                 else ans+=2;
                
//             }
//         }
//         arr[0]=0;
//         ans+=arr[i-1];
//         arr[i]=ans;
//     }


//     for(int i=10001; i<=20000; i++)
//     {
//         int ans =0;
//         for(int j=1; j<=i; j++)
//         {
//             int gcd = __gcd(i,j);
//             int lcm = (i*j)/gcd;
//             int x = lcm/gcd;
//             if(x<=3) 
//             {
//                 if(i==j) ans++;
//                 else ans+=2;
                
//             }
//         }
//         arr[0]=0;
//         ans+=arr[i-1];
//         arr[i]=ans;
//     }
// }
// int main()
// {
//     solution();
//     int t;
//     cin>>t;
//     while(t--) 
//     {
//         int n;
//         cin>>n;
//         cout<<"Ans is : "<<arr[n]<<endl;
//     }
// }

// Problem Link : https://codeforces.com/contest/1717/problem/A

#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans= n+(2*(n/2))+(2*(n/3));
        cout<<ans<<endl;
    }
}