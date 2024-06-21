/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
*/
/*

time complexity: O(n)

space complexity: O(1)

使用two pointer 設置左右pointer
在左pointer小於右pointer的情況下
計算寬和高後計算面積
比較當前面積和先前最大面積的大小
移動較小的pointer如相等移動左邊
回傳可以得到的最大面積
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int left = 0;
        int right = height.size()-1;
        int h,w = 0;
        while(left <　right){
            h = min(height[left],height[right]);
            w = right-left;
            area =  max(area, h*w);

            if(height[left]<= height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return area;
    }
};

auto init=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();