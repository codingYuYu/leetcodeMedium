/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
*/
/*

time complexity: O(n)

space complexity: O(1)

遍歷array將product乘上所有element
並計算0的個數
根據array中 0的數量 對array進行調整
如果array中 0的數量超過1個直接將所有element變成0
如果array中 0的數量等於1個根據element是否為0 
為0則element等於product
不為0則element等於0
若array中沒有0則element等於product/該element
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int product = 1;
        for(auto i : nums){
            if(i == 0){
                zero++;
                continue;
            }
            else if(zero > 1){
                break;
            }
            product*=i;
        }
        for(int i = 0; i < n; i++){
            if(zero>1 || zero==1 && nums[i]){
                nums[i]=0;
            }
            else if(zero==1 && !nums[i]){
                nums[i]=product;
            }
            else{
                nums[i]=product/nums[i];
            }
        }
        return nums;
    }
};

auto init=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
