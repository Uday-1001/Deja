// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string>ans;
        unordered_set<string>supply(supplies.begin() , supplies.end());
        vector<bool>cooked(n,false);

        int count = n;
        while(count--)
        {
            for(int i = 0 ; i<n ; i++)
            {
                if(cooked[i]) continue;
                
                bool can_make_recipe = true;

                for(int j = 0 ;j<ingredients[i].size() ; j++)
                {
                    string curr_ingredient = ingredients[i][j];
                    if(supply.find(curr_ingredient) == supply.end())
                    {
                        can_make_recipe = false;
                        break;
                    }
                }
                if(can_make_recipe)
                {
                    supply.insert(recipes[i]);
                    ans.push_back(recipes[i]);
                    cooked[i] = true;
                }
            }
        }
    return ans;
    }
};