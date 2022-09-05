
// Merge two sorted array with out taking any extra space

#include <bits/stdc++.h>
using namespace std;

int main()
{
    float len1, len2;
    cout << "Enter the first array size: ";
    cin >> len1;
    vector<int> arr;
    cout << "Please Enter array element in sorted order\n";
    for (int i = 0; i < len1; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << "Enter the 2nd  array size: ";
    cin >> len2;
    // int arr[len1];
    cout << "Please Enter array element in sorted order\n";
    for (int i = len1; i < (len2 + len1); i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    float gap;
    gap = ceil((len1 + len2) / 2);
     cout<<gap<<endl;

    do
    {
        float i =0;
        float j = gap;
        while(j!=(arr.size()))
        {
            if(arr[i]>arr[j])
            {
                swap(arr[i], arr[j]);
                i++;
                sort(arr[j], arr[len1+len2]);
                j++;    
            }
            else 
            {
                i++; 
                j++;
            }
        }

        gap = ceil(gap / 2);
    } while (gap != 1);

    cout << endl;
    cout << endl;

    // for (int i=0; i<len1; i++)
    // {
    //     cout << arr[i] << "\t";
    // }
    // cout << endl;

    // for (int i=len1; i<(len1+len2); i++)
    // {
    //     cout << arr[i] << "\t";
    // }
    // cout<<endl;

    for(auto i: arr) cout<<i<<"\t";
}