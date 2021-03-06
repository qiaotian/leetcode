/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/


// Recursion / Stack
// Not elegant enough
// 该方法将字符串s拆解成3个部分：前缀字符串，第一个[xxxx]，以及其后缀字符串三个部分
// 显然第一个部分不包含[]，第二部分可能包含嵌套，第三部分也由可能包含嵌套。
// 因此递归使用了两次，分别在第二部分和第三部分各一次。
class Solution {
public:
    string decodeString(string s) {
        if(s.empty()) return "";

        string ans = "";
        /// 1. 处理s首部的非嵌套字符串，如 s = "ef3[a]"中的“ef”
        int x = 0;
        for(int i = 0; i<s.size(); i++) {
            if(s[i]>='a' && s[i]<='z') x++; // the number of char increase
            else break;
        }
        ans += s.substr(0, x);
        s = s.substr(x);
        //cout << s << endl;

        /// 2. 处理新s的数字部分
        int cnt = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]<='9' && s[i]>='0') cnt = 10*cnt+s[i]-'0';
            else {
                s = s.substr(i); /// update string s
                break;
            }
        }
        
        //cout << s << endl;
        //cout << cnt << endl;

        /// 3. 处理嵌套部分
        int lbracket = -1; /// 最外层左括号位置，注意，有可能没有
        int rbracket = -1; /// 最外层右括号位置
        for(int i=0, cnt=0; i<s.size(); i++) {
	        if(s[i]=='[') {
                if(lbracket==-1) lbracket = i;
                cnt++;
            }
            else if(s[i]==']') {
                cnt--;
                if(cnt==0) {
                    rbracket = i;
                    break;
                }
            }
        }
        string tmp = s.substr(lbracket+1, rbracket-lbracket-1);
        //cout << tmp << endl;
        string decoded_tmp = decodeString(tmp);
        for(int j=0; j<cnt; j++) ans += decoded_tmp;
        if(rbracket!=-1) s = s.substr(rbracket+1); /// update string s
        //cout << s << endl;

        /// 4. 处理嵌套外的字符串
        ans += decodeString(s);
        return ans;
    }
};


// Official Method: Stack
// More Concise!!!
class Solution {
public:
    string decodeString(string s, int& i) {
        string res;
        
		// 出栈条件
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i])) //处理前缀字符串和后缀字符串
                res += s[i++];
            else {
				// 处理数字和[xxxx]
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';

                i++; // '['
                string t = decodeString(s, i);
                i++; // ']'
                
                while (n-- > 0)
                    res += t;
            }
        }
        
        return res;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};


/// 总结：两种方法都使用了递归处理的问题
/// 第一种方法将递归的分界设置为：左括号为起始，右括号为终止条件
/// 第二种方法将将递归的分解设为：数字为起始，右括号为终止条件
