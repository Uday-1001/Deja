// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i

class Solution {
public:
    bool isPrefixAndSuffix(string a , string b){
        int s1 = a.length();
        int s2 = b.length();
        if(s1>s2)
        {
            return false;
        }
        string prefix = b.substr(0,s1);
        string suffix = b.substr(s2-s1);

        if(prefix == a && suffix == a)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for(int i=0; i<n ; i++)
        {
            for(int j =i+1; j<=n-1 ; j++)
            {
                string str1= words[i];
                string str2= words[j];

                if(isPrefixAndSuffix(str1,str2))
                {
                    ++count ;
                }
            }
        }
        return count ;
    }
};