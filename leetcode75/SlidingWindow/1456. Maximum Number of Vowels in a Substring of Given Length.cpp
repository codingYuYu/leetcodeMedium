/*
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length
*/
/*

time complexity: O(n)

space complexity: O(n)

使用set紀錄aeiou
遍歷s 判斷每個element是否為vowel如果是則記錄在check中
使用sliding window遍歷check計算在k個element中最大可能出現vowel數量
回傳ans
*/
class Solution {
public:
    int maxVowels(string s, int k) {
        int n =  s.size();
        int ans = 0;
        int temp = 0;
        unordered_set<char> vowel{'a','e','i','o','u'};
        vector<int> check(n,0);
        for(int i =0; i < n;i++){
            if(vowel.count(s[i])){
                check[i]=1;
            }
        }
        for(int i = 0; i<n ;i++){
            if(i < k){
                temp+=check[i];
            }
            else if(i >= k){
                temp = temp-check[i-k]+check[i];
            }
            ans = max(ans,temp);
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