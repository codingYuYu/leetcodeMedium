/*
You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.
 

Example 1:

Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
Example 2:

Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters and stars *.
The operation above can be performed on s.
*/
/*

time complexity: O(N)

space complexity: O(N)

使用stack檢查字串
如果遇到 * 則pop最上面的element
否則就push進stack
在將stack中的element放進字串
由於是從最後面開始拿取必須進行reverse才能得到題目要求
*/
class Solution {
public:
    string removeStars(string s) {
        stack<char> temp;
        string ans;
        for(auto i : s){
            if(i=='*'){
                temp.pop();
            }
            else{
                temp.push(i);
            }
        }
        while(!temp.empty()){
            ans+=temp.top();
            temp.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

auto init=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
