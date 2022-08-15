#include <bits/stdc++.h>
using namespace std;
// Thanks to striver vaiya

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;

        while (mid <= high)
        {
            switch (nums[mid])
            {
            case 0:
                swap(nums[low++], nums[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid], nums[high--]);
                break;
            }
        }

        for (auto it : nums)
        {
            cout << it << "\t";
        }
    }
};

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

    Solution s;
    s.sortColors(nums);
}