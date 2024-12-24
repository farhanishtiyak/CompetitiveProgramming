// // Problem Link: https://codeforces.com/problemset/problem/230/B



#include <bits/stdc++.h>
using namespace std;
int isPrime(long long int n)
{
    int flag =1,i;
    if(n==0||n==1) return 0;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            flag =0;
            break;
        }
    }
    return flag;
}
int main()
{
    int n;
    cin >> n;
    vector<string> arr;
    for (int i = 0; i < n; i++)
    {
        long long int x;
        cin >> x;
        long long int p=sqrt(x);
        if(p*p==x)
        {
            x=x/p;
            if(isPrime(p)) arr.push_back("YES");
            else arr.push_back("NO");
        }
        else arr.push_back("NO");
    }
    for (auto tPrime : arr)
    {
        cout << tPrime << endl;
    }
}

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 10;
// vector<int> isPrime(N, 1);
// vector<int> tPrime(N, 0);
// vector<int> Tprime(N, 0);

// int main()
// {

//     isPrime[0] = 0;
//     isPrime[1] = 0;
//     for (long long int i = 2; i <= N; i++)
//     {
//         if (isPrime[i] == 1)
//         {
//             long long int x = i ;
//             if (x >= 1000000)
//             {
//                 x = x - 1000000;
//                 Tprime[x] = 1;
//             }
//             else
//                 tPrime[x] = 1;

//             for (int j = 2 * i; j <= N; j += i)
//             {
//                 isPrime[j] = 0;
//             }
//         }
//     }

//     int n;
//     cin >> n;
//     vector<string> arr;
//     for (int i = 0; i < n; i++)
//     {
//         long long int x;
//         cin >> x;
//         // x=sqrt(x);
//         if (x >= 1000000)
//         {
//             x = x - 1000000;
//             if (Tprime[x] == 1)
//                 arr.push_back("YES");
//             else
//                 arr.push_back("NO");
//         }
//         else
//         {
//             if (tPrime[x] == 1)
//                 arr.push_back("YES");
//             else
//                 arr.push_back("NO");
//         }
//     }
//     for (auto tPrime : arr)
//     {
//         cout << tPrime << endl;
//     }
// }


// // Problem Link: https://codeforces.com/problemset/problem/230/B

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 10;
// vector<int> isPrime(N, 1);

// // checking that square root of array elements integer or not
// bool is_integer(float check){
//         if (int(check) == check)
//                 return true;
//         else return false;
// }
// int main()
// {
//     // Storing Prime Numbers
//     isPrime[0] = 0;
//     isPrime[1] = 0;
//     for (long long int i = 2; i< N; i++)
//     {
//         if (isPrime[i] == 1)
//         {
//             for (int j = 2*i; j < N; j += i)
//             {
//                 isPrime[j] = 0;
//             }
//         }
//     }

//     int n;
//     cin >> n;
//     vector<string> arr;
//     for (int i = 0; i < n; i++)
//     {
//         long long int x;
//         cin >> x;
//         float p =sqrt(x);
//         // If p is a float value then no need to check prime or not
//         if(is_integer(p))
//         {
//             if(isPrime[p]) arr.push_back("YES");
//             else arr.push_back("NO");
//         }
//         else arr.push_back("NO");  
        
//     }
//     for (auto tPrime : arr)
//     {
//         cout << tPrime << endl;
//     }
// }


