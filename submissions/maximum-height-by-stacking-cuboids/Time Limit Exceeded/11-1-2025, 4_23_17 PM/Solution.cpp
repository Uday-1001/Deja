// https://leetcode.com/problems/maximum-height-by-stacking-cuboids

class Solution {
public:
    bool isValidToPlace(vector<int>cuboid1 , vector<int>cuboid2)
    {
        return (cuboid1[0] <= cuboid2[0] && cuboid1[1] <= cuboid2[1] && cuboid1[2] <= cuboid2[2]);
    }

    int byrec(vector<vector<int>>&cuboids , int prev , int curr)
    {
        //base case
        if(curr >= cuboids.size()) return 0; 

        //ek case hum solve karenge baaki ka recursion sambhalega 
        int include = 0;
        if(prev == -1 || isValidToPlace(cuboids[prev] , cuboids[curr]))
        {
            include = cuboids[curr][2] + byrec(cuboids , curr , curr+1);
        }
        int exclude = 0 + byrec(cuboids , prev , curr+1);
        return max(include , exclude);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid : cuboids)
        {
            sort(cuboid.begin() , cuboid.end());
        }
        sort(cuboids.begin() , cuboids.end());

        return byrec(cuboids , -1 , 0);
    }
};