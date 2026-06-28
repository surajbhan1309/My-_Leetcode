class MinStack {
    stack<long long> s; // Use long long to avoid overflow issues
    long long mini;     // Track minimum value
    
public:
    MinStack() {
        mini = LLONG_MAX; // Initialize mini with maximum value for long long
    }
    
    void push(int val) {
        if (s.empty()) {
            s.push(val);  // Directly push the value when stack is empty
            mini = val;   // Update the minimum value
        }
        else {
            if (val < mini) {
                // Push the encoded value to track the minimum
                s.push(2LL * val - mini); // Use long long for the calculation
                mini = val;               // Update the minimum
            } 
            else {
                s.push(val);
            }
        }
    }
    
    void pop() {
        if (s.empty()) {
            return;
        }
        long long curr = s.top();
        s.pop();
        
        // Check if the current top is the encoded value
        if (curr < mini) {
            mini = 2LL * mini - curr; // Restore previous minimum (using long long)
        }
    }
    
    int top() {
        if (s.empty()) {
            return -1;
        }
        long long curr = s.top();
        
        if (curr < mini) {
            // The current top is an encoded value, so return the actual minimum
            return mini;
        } 
        else {
            return curr;
        }
    }
    
    int getMin() {
        if (s.empty()) {
            return -1;
        }
        return mini;
    }
};
