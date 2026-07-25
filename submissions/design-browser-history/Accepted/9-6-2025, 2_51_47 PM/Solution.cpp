// https://leetcode.com/problems/design-browser-history

class BrowserHistory {
public:
    stack<string> Browserpg , Forwardpg;

    BrowserHistory(string homepage) {
        Browserpg.push(homepage);
    }
    
    void visit(string url) {
        while(!Forwardpg.empty())
        {
            Forwardpg.pop();
        }
    Browserpg.push(url);
    }
    
    string back(int steps) {
        while(steps--)
        {
            if(Browserpg.size() > 1)
            {
                Forwardpg.push(Browserpg.top());
                Browserpg.pop();
            }
            else
            {
                break;
            }
        }
    return Browserpg.top();
    }
    
    string forward(int steps) {
        while(steps--)
        {
            if(Forwardpg.size() > 0)
            {
                Browserpg.push(Forwardpg.top());
                Forwardpg.pop();
            }
            else
            {
                break;
            }
        }
    return Browserpg.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */