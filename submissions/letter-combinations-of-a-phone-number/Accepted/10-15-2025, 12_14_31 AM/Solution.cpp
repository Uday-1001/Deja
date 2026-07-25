// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    void solve(string &output , unordered_map<char,string>&map , vector<string>&ans , string digits , int i)
    {
        //base case 
        if(i >= digits.size())
        {
            if(output.size() > 0)
            {
                ans.push_back(output);
            }
            return;
        }
        char digit = digits[i];
        string mapped_string = map[digit];

        for(char ch : mapped_string)
        {
            output.push_back(ch);
            solve(output , map , ans , digits , i+1);

            //backtrack
            output.pop_back();        
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string>ans;

        unordered_map<char,string>map;

        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";

        string output = "";

        solve(output , map , ans , digits , 0);
        return ans;
    }
};