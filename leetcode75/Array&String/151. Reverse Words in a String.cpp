/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/
/* 

time complexity: O(n)

space complexity: O(n)

先使用istreamstring將字串根據空白分開成個別單字
push到words這個stack中
利用stack先進後出的機制
使用迴圈每次將stack中最上方的單字加到ans中並pop掉直到stack中沒有單字
回傳答案即為所求
*/
class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        stack<string> words;
        string word;
        
        while (is >> word) {
            words.push(word);
        }
        
        string ans;
        while (!words.empty()) {
            ans += words.top();
            words.pop();
            if (!words.empty()) {
                ans += " ";
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
