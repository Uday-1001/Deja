// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    priority_queue<double>maxheap;
    priority_queue<double,vector<double>,greater<double>>minheap;
    double median;

    MedianFinder() 
    {
        //array is divided into two parts -> left part is the maxheap and right part is the minheap
        //the median becomes = (max of the leftpart + min of the right part) / 2 
        //we need not to see other elements and consider only these elements for answer.

        median = 0.0;
    }
    
    void addNum(int num) {
        //means that the sizes of both the heaps is same 
        if(maxheap.size() == minheap.size())
        {
            if(num > median)
            {
                //insert in the right part -> min of right part is the required ans as size increments of minheap
                minheap.push(num);
                median = minheap.top();
            }
            else
            {
                //insert in the leftpart -> max of left part is the required ans as size increments of maxheap
                maxheap.push(num);
                median = maxheap.top();
            }
        }
        //means that the size of maxheap is greater by 1
        else if(maxheap.size() - minheap.size() == 1)
        {
            if(num > median)
            {
                //minheap has lesser size so -> direct insert 
                minheap.push(num);
                //now after insertion size of both heaps becomes equal
                median = (maxheap.top() + minheap.top()) / 2.0;
            }
            else
            {
                //insertion cant happen directly but we have to pull out one element from max heap 
                double top_maxheap = maxheap.top();
                maxheap.pop();
                minheap.push(top_maxheap);

                maxheap.push(num);
                median = (maxheap.top() + minheap.top()) / 2.0;
            }
        }
        else
        {
            if(num > median)
            {
                //insertion cant happen directly but we have to pull out one element from min heap 
                double top_minheap = minheap.top();
                minheap.pop();
                maxheap.push(top_minheap);

                minheap.push(num);
                median = (maxheap.top() + minheap.top()) / 2.0;
            }
            else
            {
                //maxheap has lesser size so -> direct insert 
                maxheap.push(num);
                //now after insertion size of both heaps becomes equal
                median = (maxheap.top() + minheap.top()) / 2.0;
            }
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */