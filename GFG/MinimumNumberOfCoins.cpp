#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int>answer;
        int arr[] = {1,2,5,10,20,50,100,200,500,2000};
        int n = 10;
        int i=9;
        while(N!=0)
        {
            
            if(N>=arr[i])
            {
                N-=arr[i];
                answer.push_back(arr[i]);
            }
            else i--;
        }
        return answer;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
