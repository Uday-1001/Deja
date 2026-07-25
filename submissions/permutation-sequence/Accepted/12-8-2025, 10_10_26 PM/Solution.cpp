// https://leetcode.com/problems/permutation-sequence

class Solution {
public:
    void byrec(int n , int k , string &s , int fact_val , string &ans)
    {
        //base case
        if(n == 0) return;

        //ek no hum put karenge , baaki ka recursion kardega
        int partsize = fact_val / n;
        int index_of_char = (k-1) / partsize;

        //answer construction here
        ans += s[index_of_char];

        //just erase that character from the string 
        s.erase(s.begin() + index_of_char);
        
        //update the k and fact_val to new value
        k = k - (index_of_char * partsize);
        fact_val = partsize;

        byrec(n-1 , k , s , fact_val , ans);
    }

    string getPermutation(int n, int k) {
        string s = "";
        int fact_val = 1;
        for(int i = 1 ; i<=n ; i++)
        {
            s.push_back(i + '0');
            fact_val *= i;
        } 

        string ans = "";
        byrec(n , k , s , fact_val , ans);
        return ans;
    }
};