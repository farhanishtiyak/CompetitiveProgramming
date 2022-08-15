#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
    void FindCombination(int index, int target, vector<int>&arr, vector<int>&ds, vector<vector<int>> &ans){
        if(index==arr.size()){
            if(target == 0) ans.push_back(ds);
            return;
        }

        // pick the index
        if(arr[index] <= target){
            ds.push_back(arr[index]);
            FindCombination(index, target-arr[index], arr, ds, ans);
            ds.pop_back();
        }
        // pick the next index
        FindCombination(index+1, target, arr, ds, ans);

    }


    public:
    vector<vector<int>> CombinationSum(vector<int>& arr, int target){
        vector<vector<int>> answer;
        vector<int>ds;
        FindCombination(0,target,arr,ds,answer);
        return answer;
    }

};

int main(){
    int n;
    //cout<<"Enter how many number you want: ";
    cin>>n;
    vector<int> candidates;
    //cout<<"Enter Candidates number:"<<endl;
    while(n--){
        int v;
        cin>>v;
        candidates.emplace_back(v);
    }

    int target;
    //cout<<"Enter your target: ";
    cin>> target;

     vector<vector<int>> answer;
    Solution combinationSum;
    answer = combinationSum.CombinationSum(candidates, target);

    //cout<<"******Combinations Are******"<<endl;

    for(auto it1 : answer){
        for(auto it2: it1){
            cout<<it2<<"\t";
        }
        cout<<endl;
    }

}