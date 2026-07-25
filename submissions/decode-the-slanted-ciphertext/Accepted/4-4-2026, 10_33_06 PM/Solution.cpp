// https://leetcode.com/problems/decode-the-slanted-ciphertext

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string ans = "";
        int cols = encodedText.size() / rows;

        for(int i = 0 ; i<cols ; i++)
        {
            for(int j = i ; j<encodedText.size() ; j+=cols+1) ans.push_back(encodedText[j]);
        }

        while(!ans.empty() and ans.back() == ' ') ans.pop_back();
        return ans;
    }
};