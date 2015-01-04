class MinStack {
public:
    void push(int x) {
        data.push(x);
        if (0 == min.size()) {
            min.push(x);
            min_count.push(1);
        } else {
            int min_top = min.top();
            if (x < min_top) {
                min.push(x);
                min_count.push(1);
            } else {
                int top_min_count = min_count.top();
                min_count.pop();
                min_count.push(top_min_count + 1);
            }
        }
    }

    void pop() {
        data.pop();
        int top_min_count = min_count.top();
        min_count.pop();
        if (top_min_count > 1) {
            min_count.push(top_min_count - 1);
        } else {
            min.pop();
        }
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
    }
    
private:
    stack<int> data;
    stack<int> min;
    stack<int> min_count;
};