class MedianFinder {
public:
    priority_queue<int>maxheap;//to store low numbers 
    priority_queue<int,vector<int>,greater<int>>minheap;//to store high numbers;

    //maxheap gives the highest among the lowest and mineheap gives the lowest among the highest
    //like maxheap have 1,2,3,5,8 and minheap have 10,21,99 so median of 8 and 10 wil be answer; 
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);
        minheap.push(maxheap.top());
        maxheap.pop();
        if(minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        
    }
    
    double findMedian() {
        if(maxheap.size()>minheap.size()) return maxheap.top();
        return (maxheap.top()+minheap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */