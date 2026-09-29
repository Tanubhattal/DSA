class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=1;
        int mx=nums[0];
        int mn=1;
        for(int i=0; i<nums.size();i++){
         int temp=prod;
         prod = max({nums[i], nums[i]*prod , nums[i]*mn}) ;
         mn= min({nums[i], nums[i]*temp, nums[i]*mn});

         mx=max(prod,mx);
        }
        return mx;
    }
};