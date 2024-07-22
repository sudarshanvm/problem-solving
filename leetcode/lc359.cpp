//problem: https://leetcode.com/problems/logger-rate-limiter/
class Logger {
public:
    unordered_map<string,int> m;
    vector< pair<int,string> > res;
    Logger() {
       
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(m.find(message)==NULL)
        {
            m[message] = timestamp;
            return true;
        }

        if(abs(m[message]-timestamp)>=10)
        {
            m[message] = timestamp;
            return true;
        }

        
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
