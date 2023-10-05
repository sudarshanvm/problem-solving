//problem : https://leetcode.com/problems/ternary-expression-parser/

class Solution {
public:

    string parseTernary(string expression) {
        stack<char>s;
        int index = expression.size()-1;
        while(index>=0)
        {
            char cur = expression[index];
            if(cur==':')
            {
                index--;
                continue;
            }
            if(cur=='?')
            {
                char ontrue = s.top(); s.pop();
                char onfalse = s.top(); s.pop();
                char flag = expression[index-1];
                if(flag=='T')
                    s.push(ontrue);
                    
                else if(flag=='F')
                    s.push(onfalse);
                    
                index--;
                
            }
            else if(cur>='0'||cur<='9'||cur=='T'||cur=='F')
                s.push(cur);
            index--;
        }

        string res(1,s.top());

        return res;
    }
};
