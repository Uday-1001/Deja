// https://leetcode.com/problems/count-collisions-on-a-road

class Solution {
public:
    int countCollisions(string directions) {
        int collide = 0;

        int i = 0;
        int j = directions.size()-1;
        
        //skip the same direction cars
        while(directions[i] == 'L') i++;
        while(directions[j] == 'R') j--;

        for(int k = i ; k<=j ; k++)
        {
            if(directions[k] != 'S') collide ++;
            else continue;
        }

        return collide;        
    }
};