class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int max = 0;
        for( int num :nums){
            if (count == 0){
                max = num;
            }
            if (num == max){
                count++;
            }
            else{
                count--;
            }
        }
        return max;
    }
};