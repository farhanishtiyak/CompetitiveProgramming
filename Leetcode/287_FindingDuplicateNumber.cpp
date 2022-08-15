#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=nums[0];        
        int f=nums[0];
        do{
            s=nums[s];
            f=nums[nums[f]];
        }while(s!=f);
        
        f=nums[0];
            while(s!=f)
            {
                s=nums[s];
                f=nums[f];
            }
        return f;

    }
};

int main()
{
    int n;
    vector<int> nums;
    cin>>n;
    while(n--) 
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }

    Solution s;
    int duplicate = s.findDuplicate(nums);
    cout<<"\nDuplicate number is : ";
    cout<<duplicate<<endl<<endl;
}