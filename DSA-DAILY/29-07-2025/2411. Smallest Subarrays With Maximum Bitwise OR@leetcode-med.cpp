class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n); 
        for(int i=0;i<n;i++){
            int x=nums[i];
            ans[i]=1;
            for(int j=i-1;j>=0&&(nums[j]|x)!=nums[j];--j){
                nums[j]|=x;
                ans[j]=i-j+1;
            }
        }
        return ans;
    }
};
int main(){
  Solution sol;
  int n;
  cout<<"Enter size of array:";
  cin>>n;
  cout<<"Enter Array:"
  vector<int> n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  smallestSubarrays(nums);
  return 0;
}
