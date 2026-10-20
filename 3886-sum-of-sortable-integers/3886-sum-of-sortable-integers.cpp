class Solution {
public:
    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        for (int k = 1; 1LL * k * k <= n; k++) {
            if (n % k == 0) {
                if (check(nums, k)) ans += k;
                
                int other = n / k;
                if (other != k && check(nums, other)) 
                    ans += other;
            }
        }
        
        return ans;
    }
    
    bool check(vector<int>& nums, int k) {
        int n = nums.size();
        int prevMax = 0;
        
        for (int s = 0; s < n; s += k) {
            int mn = nums[s], mx = nums[s];
            int desc = 0;
            
            for (int i = s; i < s + k; i++) {
                int j = (i + 1 == s + k) ? s : i + 1;
                
                if (nums[i] > nums[j]) desc++;
                if (desc > 1) return false;
                
                mn = min(mn, nums[i]);
                mx = max(mx, nums[i]);
            }
            
            if (s > 0 && prevMax > mn) return false;
            prevMax = mx;
        }
        
        return true;
    }
};