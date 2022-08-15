#include<bits/stdc++.h>
using namespace std;


int repeatElement(vector<int>&nums)
{
    int slow = nums[0];
    int fast=nums[0];

    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow!=fast);
    while(slow!=fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return fast;
}

int missingElement(vector<int>&n)
{
    int XoR = 0;
    int s = n.size();
    for(int i=0; i<s; i++)
    {
        XoR = XoR^n[i];
    }
    return XoR;
}
int main()
{
    int n;
    cout << "Enter array Size: ";
    cin >> n;
    vector<int> nums;
    while (n--)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    // Repeating Element
    int repeat= repeatElement(nums);
    cout<<"Repeating Element is : "<<repeat<<endl;
    // missing element using xor property
    int missing = missingElement(nums);
    cout<<"Missing Element is : "<<missing<<endl;

}