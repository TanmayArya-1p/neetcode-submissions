class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        auto evalBOP = [&](int a, int b, char op) -> int {
            switch(op) {
                case '+' :
                    return a+b;
                case '-':
                    return a-b;
                case '*':
                    return a*b;
                case '/':
                    return a/b;
            }
        };


        for (auto &c : tokens) {
            if(c=="+" || c=="-" ||c=="*" ||c=="/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(evalBOP(a,b, c[0]));
            }
            else st.push(stoi(c));
        }
        return st.top();
    }
};
