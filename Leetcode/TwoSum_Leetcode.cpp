#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    vector<int> answer;
    vector<int> twoSum(vector<int>&nums, int target){
        
        unordered_map<int, int> mpp;

        for(int i=0; i<nums.size(); i++){

            if(mpp.find((target-nums[i])) !=mpp.end()){
                answer.emplace_back(mpp[target-nums[i]]);
                answer.emplace_back(i);
                return answer;
            }

            mpp[nums[i]] = i;
        }

        return {-1};
    }
};


int main(){
    int n;
    cout<<"Enter your array size: ";
    cin>>n;
    cout<<"Enter elements: "<<endl;
    vector<int> arr;
    while(n--){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int target;
    cout<<"Enter target: ";
    cin>>target;
    Solution obj;
    vector<int> ans;
    
    cout<<"***Indices Are****"<<endl<<endl;
    ans = obj.twoSum(arr, target);
    for(auto it: ans) {
        cout<<it<<"\t";
    }
    
}