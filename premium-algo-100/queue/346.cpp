//problem: https://leetcode.com/problems/moving-average-from-data-stream/

class MovingAverage {
public:

    queue<double>q;
    int count=0;
    double sum=0;
    int window;
    MovingAverage(int size) {
        window = size;
    }
    
    double next(int val) {
        q.push(val);
        count++;
        sum += val;
        if(count>window)
        {
            sum -= q.front();
            q.pop();
            count = window;
        } 

        return sum/count;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
