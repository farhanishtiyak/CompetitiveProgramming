// Problem Link: https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1?page=2&category[]=Arrays&curated[]=1&sortBy=submissions


#include <bits/stdc++.h>

using namespace std;


bool comp(string x, string y)
{
    string xy = x+y;
    string yx = y+x;
    return xy.compare(yx)>0?true:false;
}

class Solution{
public:
	string answer="";
	string printLargest(vector<string> &arr) {
	    sort(arr.begin(), arr.end(), comp);
	    for(auto it = arr.begin(); it!=arr.end(); it++)
	    {
	        answer+=*it;
	    }
	    return answer;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}
