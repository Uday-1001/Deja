// https://leetcode.com/problems/walking-robot-simulation-ii

class Robot {
public:
    tuple<int,int,string> info;
    int n , m;

    Robot(int width, int height) {
        n = height;
        m = width;
        info = {0 , 0 , "East"};
    }
    
    void step(int num) {   
        while(num > 0)
        {
            int ht = get<0>(info);
            int width = get<1>(info);
            string dir = get<2>(info);

            if(dir == "East")
            {
                if(num + width <= m-1)
                {
                    get<1>(info) = width + num;
                    num = 0;
                }
                else
                {
                    num -= (m-1-width);
                    get<1>(info) = m-1;
                    get<2>(info) = "North";
                }
            }
            else if(dir == "North")
            {
                if(num + ht <= n-1)
                {
                    get<0>(info) = ht + num;
                    num = 0;
                }
                else
                {
                    num -= (n-1-ht);
                    get<0>(info) = n-1;
                    get<2>(info) = "West";
                }
            }
            else if(dir == "West")
            {
                if(num <= width)
                {
                    get<1>(info) = width - num;
                    num = 0;
                }
                else
                {
                    num -= width;
                    get<1>(info) = 0;
                    get<2>(info) = "South";
                }
            }
            else
            {
                if(num <= ht)
                {
                    get<0>(info) = ht - num;
                    num = 0;
                }
                else
                {
                    num -= ht;
                    get<0>(info) = 0;
                    get<2>(info) = "East";
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {get<1>(info) , get<0>(info)};
    }
    
    string getDir() {
        return get<2>(info);
    }
};