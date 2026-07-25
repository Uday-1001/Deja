// https://leetcode.com/problems/car-fleet-ii

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {

        stack<int>st;

        vector<double> answer(cars.size() , -1);
         
        for(int i=cars.size()-1 ; i>=0 ; i--)
        {
            int pos = cars[i][0];
            int speed = cars[i][1]; 

            while(!st.empty())
            {
                //index at top of stack
                int j = st.top();
                //top of stack position
                int tos_pos = cars[j][0];
                int tos_speed = cars[j][1];

                if(speed <= tos_speed)
                {
                    //cant collide as the speed is less than that of ahead car
                    st.pop();
                    // continue;
                }

                //calculating the collision time if the behind car is faster than ahead one
                double collision_time = (double)(tos_pos - pos) / (speed - tos_speed);

                //if the calculated collide time for the car is greater than the previous calc. collision time
                //then pop the car as it will not collide with the current car 
                if(answer[j] > 0 && collision_time >= answer[j])
                {
                    st.pop();
                }
                else
                {
                    //update the time in answer array and break immediately for next car calculation
                    answer[i] = collision_time;
                    break;
                }
            }
            st.push(i);
        }
    return answer;
    }
};