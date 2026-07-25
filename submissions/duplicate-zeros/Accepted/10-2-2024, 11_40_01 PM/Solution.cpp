// https://leetcode.com/problems/duplicate-zeros

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int>a;
        int m=arr.size();
        for(int i=0;i<arr.size();i++)
        {
        if(arr[i]==0){
            a.push_back(0);
            a.push_back(0);
        }
        else{
            a.push_back(arr[i]);
        }
        }
        for(int i=0;i<m;i++)
        {
            arr[i]=a[i];
        }
        
    }
};