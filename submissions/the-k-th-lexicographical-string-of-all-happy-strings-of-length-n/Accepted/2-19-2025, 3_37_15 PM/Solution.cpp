// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n

class Solution {
public:

    int count = 0 ;
    string result = "";

    void recursion(int n , int k , string current)
    {
        //base case 
        if(current.size() == n)
        {
            count ++;
            if(count == k)
            {
                result = current ;
            }
            return;
        }

        //ek case solve krdenge baaki recursion kardega 
        char array[3] = {'a' ,'b' , 'c'};

        for(int i = 0 ; i<3 ; i++)
        {
            char ch = array[i];
            
            if(current.empty() or current.back() != ch)
            {
                recursion(n , k , current + ch);

                if(!result.empty()) return;
            }
        }
    }

    string getHappyString(int n, int k) {
        recursion( n , k , "");
        return result;
    }
};