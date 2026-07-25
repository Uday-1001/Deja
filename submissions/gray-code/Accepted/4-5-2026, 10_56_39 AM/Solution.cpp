// https://leetcode.com/problems/gray-code

class Solution {
public: 
    int conversion(string str)
    {
        int num = 0;
        for(int i = 0 ; i<str.size() ; i++) num = num * 2 + (str[i] - '0');
        return num;
    }

    vector<int> convertToInteger(vector<string>&binary)
    {
        vector<int>ans;
        for(int i = 0 ; i<binary.size() ; i++)
        {
            string binarystr = binary[i];
            ans.push_back(conversion(binarystr));
        }
        return ans;
    }

    vector<string> byrec(int n)
    {
        if(n == 1)
        {
            return {"0", "1"};
        }
        
        vector<string>prev = byrec(n - 1);
        vector<string>binary;
        
        for(int i = 0 ; i<prev.size() ; i++)
        {
            binary.push_back("0" + prev[i]);
        }
        
        for(int i = prev.size() - 1 ; i>=0 ; i--)
        {
            binary.push_back("1" + prev[i]);
        }
        
        return binary;
    }

    vector<int> grayCode(int n) {
        auto ans = byrec(n);
        return convertToInteger(ans);
    }
};