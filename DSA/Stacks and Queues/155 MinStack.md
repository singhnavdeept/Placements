using two stacks
```cpp
class MinStack {

public:

    MinStack() {

    }

    stack<int>st;

    stack<int>minst;

    void push(int val) {

        st.push(val);

        if(minst.empty()){

        minst.push(val);}

        else{

            minst.push(min(val,minst.top()));

        }

    }

    void pop() {

        st.pop();

        minst.pop();

    }

    int top() {

        return st.top();

    }

    int getMin() {

        return minst.top();

    }

};
```