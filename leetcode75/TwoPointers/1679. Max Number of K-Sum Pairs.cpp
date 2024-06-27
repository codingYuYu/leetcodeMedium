/*
You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

 

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109
*/
/*

time complexity: O(n)

space complexity: O(1)

使用two pointer技巧 
head pointer 指到nums第0個element
tail pointer 指到nums最後一個element
先將nums sort一次
使用while迴圈遍歷nums直到head大於等於tail
如果head和tail相加==k則ans+1並移動head及tail
否則當相加大於k時將tail往左移
小於時則移動head往右移
最後回傳得到的ans
*/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        int head = 0;
        int tail = nums.size()-1;
        int temp = 0;
        sort(nums.begin(),nums.end());
        while(head < tail){
            temp = nums[head]+nums[tail];
            if(temp==k){
                ans++;
                head++;
                tail--;
            }
            else if(temp > k){
                tail--;
            }
            else{
                head++;
            }
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
