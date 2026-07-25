// https://leetcode.com/problems/maximum-height-by-stacking-cuboids

class Solution {
public:
    bool isValidToPlace(vector<int>cuboid1 , vector<int>cuboid2)
    {
        return (cuboid1[0] <= cuboid2[0] && cuboid1[1] <= cuboid2[1] && cuboid1[2] <= cuboid2[2]);
    }

    // int byspace_op2(vector<vector<int>>&cuboids)
    // {
    //     int n = cuboids.size();
    //     vector<int>curr_row(n+1 , 0);
    //     vector<int>next_row(n+1 , 0);

    //     for(int curr=n-1 ; curr >= 0 ; curr--)
    //     {
    //         for(int prev =curr-1 ; prev >= -1  ; prev--)
    //         {
    //             int include = 0;
    //             if(prev == -1 || isValidToPlace(cuboids[prev] , cuboids[curr]))
    //             {
    //                 include = cuboids[curr][2] + next_row[curr+1];
    //             }
    //             int exclude = 0 + next_row[curr+1];
    //             curr_row[prev+1] = max(include , exclude);
    //         }
    //         next_row = curr_row;
    //     }
    // return curr_row[0];  
    // }

    int byspace_op1(vector<vector<int>>&cuboids)
    {
        int n = cuboids.size();
        vector<int>curr_row(n+1 , 0);
        vector<int>next_row(n+1 , 0);

        for(int curr=n-1 ; curr >= 0 ; curr--)
        {
            for(int prev =curr-1 ; prev >= -1  ; prev--)
            {
                int include = 0;
                if(prev == -1 || isValidToPlace(cuboids[prev] , cuboids[curr]))
                {
                    include = cuboids[curr][2] + next_row[curr+1];
                }
                int exclude = 0 + next_row[curr+1];
                curr_row[prev+1] = max(include , exclude);
            }
            next_row = curr_row;
        }
    return curr_row[0];  
    }

    // int bytab(vector<vector<int>>&cuboids)
    // {
    //     int n = cuboids.size();
    //     vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));

    //     for(int curr=n-1 ; curr >= 0 ; curr--)
    //     {
    //         for(int prev =curr-1 ; prev >= -1  ; prev--)
    //         {
    //             int include = 0;
    //             if(prev == -1 || isValidToPlace(cuboids[prev] , cuboids[curr]))
    //             {
    //                 include = cuboids[curr][2] + dp[curr+1][curr+1];
    //             }
    //             int exclude = 0 + dp[prev+1][curr+1];
    //             dp[prev+1][curr] = max(include , exclude);
    //         }
    //     }
    // return dp[0][0];
    // }

    // int bymemo(vector<vector<int>>&cuboids , int prev , int curr , vector<vector<int>>&dp)
    // {
    //     //base case
    //     if(curr >= cuboids.size()) return 0; 
    //     if(dp[prev+1][curr] != -1) return dp[prev+1][curr];

    //     //ek case hum solve karenge baaki ka recursion sambhalega 
    //     int include = 0;
    //     if(prev == -1 || isValidToPlace(cuboids[prev] , cuboids[curr]))
    //     {
    //         include = cuboids[curr][2] + bymemo(cuboids , curr , curr+1 , dp);
    //     }
    //     int exclude = 0 + bymemo(cuboids , prev , curr+1 , dp);
    //     return dp[prev+1][curr] = max(include , exclude);
    // }

    // int byrec(vector<vector<int>>&cuboids , int prev , int curr)
    // {
    //     //base case
    //     if(curr >= cuboids.size()) return 0; 

    //     //ek case hum solve karenge baaki ka recursion sambhalega 
    //     int include = 0;
    //     if(prev == -1 || isValidToPlace(cuboids[prev] , cuboids[curr]))
    //     {
    //         include = cuboids[curr][2] + byrec(cuboids , curr , curr+1);
    //     }
    //     int exclude = 0 + byrec(cuboids , prev , curr+1);
    //     return max(include , exclude);
    // }

    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for(auto &cuboid : cuboids)
        {
            sort(cuboid.begin() , cuboid.end());
        }
        sort(cuboids.begin() , cuboids.end());

        // return byrec(cuboids , -1 , 0);

        // vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        // return bymemo(cuboids , -1 , 0 , dp);

        // return bytab(cuboids);

        return byspace_op1(cuboids);    
    }
};