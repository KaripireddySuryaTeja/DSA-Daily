#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int num) {
        int i=0;
        vector<vector<int>> dp;
        dp.push_back({1});
        for(int i=1;i<num;i++){
            vector<int> curr;
            vector<int>& prev=dp[i-1];
            curr.push_back(1);
            for(int j=1;j<i;j++){
                curr.push_back(prev[j-1]+prev[j]);
            }
            curr.push_back(1);
            dp.push_back(curr);
        }
        return dp;
    }
};

int main(){
    Solution sol;
    int n;
    cin>>n;
    vector<vector<int>> result = sol.generate(n);
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}