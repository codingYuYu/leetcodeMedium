/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/
/*

time complexity: O(n)

space complexity: O(1)

遍歷nums如果第j個element cost++
當cost>k個時移動i到上一個0出現的位置
比較最後的答案及j-i的大小找出符合條件的連續1
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int i = 0, j = 0;
        int ans = 0, cost = 0, n = nums.size();
        while(j<n){
            if(nums[j]==0){
                cost++;
            }
            j++;
            while(cost > k){ 
                if(nums[i]==0){
                    cost--;
                }
                i++;
            }
            ans = max(ans, j-i);
        }    
        return ans;
    }
};

auto init=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
