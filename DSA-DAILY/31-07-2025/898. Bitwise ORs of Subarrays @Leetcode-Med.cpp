#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res,curr;
        for(int i:arr){
            unordered_set<int>temp;
            temp.insert(i);
            for(int j:curr){
                temp.insert(i|j);
            }
            res.insert(temp.begin(),temp.end());
            curr=temp;
        }
        return res.size();
    }
};
int main() {
    Solution sol;
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter Array: ";
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = sol.subarrayBitwiseORs(arr);
    cout << "Number of distinct bitwise ORs of subarrays: " << result << endl;
    return 0;
}