// https://leetcode.com/problems/coupon-code-validator

class Solution {
public:
    bool couponcheck(string &coupon , vector<bool>&isActive , int i)
    {
        if(coupon == "") return false;
        if(isActive[i] == false) return false;
        for(auto ch : coupon) 
        { 
            if(!(islower(ch) or isupper(ch) or isdigit(ch) or ch == '_')) return false;
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string>ans;
        
        vector<string> electronics , grocery , pharmacy , restaurant;
        for(int i=0 ; i<code.size() ; i++)
        {
            if(!couponcheck(code[i] , isActive , i)) continue;

            if(businessLine[i] == "electronics") electronics.push_back(code[i]);
            if(businessLine[i] == "grocery") grocery.push_back(code[i]);
            if(businessLine[i] == "pharmacy") pharmacy.push_back(code[i]);
            if(businessLine[i] == "restaurant") restaurant.push_back(code[i]);
        }

        sort(electronics.begin() , electronics.end());
        sort(grocery.begin() , grocery.end());
        sort(pharmacy.begin() , pharmacy.end());
        sort(restaurant.begin() , restaurant.end());

        for(int i=0 ; i<electronics.size() ; i++) ans.push_back(electronics[i]);
        for(int i=0 ; i<grocery.size() ; i++) ans.push_back(grocery[i]);
        for(int i=0 ; i<pharmacy.size() ; i++) ans.push_back(pharmacy[i]);
        for(int i=0 ; i<restaurant.size() ; i++) ans.push_back(restaurant[i]);

        return ans;
    }

};