// https://leetcode.com/problems/find-unique-binary-string

class Solution {
public:
    string result = "";

    bool recursion(unordered_set<string>&numbers , string &curr , int n)
    {
        //base case 
        if(curr.size() ==n)
        {
            result= curr;
            return true;
        }
        return false;

        //ek case hum solve karenge aur baaki recursion krdega 
        //try out by pushing 0
        curr.push_back('0');
        if(recursion(numbers , curr , n)) return true;
        curr.pop_back();

        //if not the upper case then try out pushing 1
        curr.push_back('1');
        if(recursion(numbers , curr , n)) return true;
        curr.pop_back();
    }

    string findDifferentBinaryString(vector<string>& nums) {
      int n = nums.size();

      unordered_set<string>numbers(nums.begin() , nums.end());

      recursion(numbers , "" , n);
      return result;  
    }
};