// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n

class Solution {
public:
    vector<string>ans;
    void byrec(int n , int k , string formed)
    {
        //base case 
        if(formed.size() == n)
        {
            ans.push_back(formed);
            return;
        }

        vector<char>arr = {'a' , 'b' , 'c'};
        for(int i = 0 ; i<3 ; i++)
        {
            if(formed.empty() or formed.back() != arr[i])
            {
                byrec(n , k , formed + arr[i]);
            }
        }
    }

    string getHappyString(int n, int k) {
        byrec(n , k , "");
        if(ans.size() < k) return "";

        sort(begin(ans) , end(ans));
        return ans[k-1];
    }
};