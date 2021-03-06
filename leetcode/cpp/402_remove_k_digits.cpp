/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

// 核心思想：先生成一个最小递增序列，然后删除多余字母，即可得到解
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k) return "0";
        string ans;
        for(auto c:num) {
            if(ans.empty() || c>=ans.back()) ans.push_back(c);
            else {
                while(!ans.empty() && c<ans.back() && k>0) {
                    ans.pop_back();
                    k--;
                }
                ans.push_back(c);
            }
        }
        // delete leading zeros
        int nonzero = -1;
        for(int i=0; i<ans.size(); i++) {
            if(ans[i] != '0') {
                nonzero = i;
                break;
            }
        }
        if(nonzero == -1) return "0";
        else {
            ans = ans.substr(nonzero);
            return ans.substr(0, ans.size()-k);
        }
    }
};
