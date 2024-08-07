class MedianFinder {
public:
    priority_queue<int>max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    MedianFinder() {}
    //int /2 wil give int nbut double/2 - double hi give
    
    void addNum(int num) {
        max_heap.push(num);
        if (max_heap.size()>1+min_heap.size()){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if (!max_heap.empty()&&!min_heap.empty()&&
            max_heap.top()>min_heap.top()){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if(min_heap.size() > max_heap.size()+1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        return;
    }
    
    double findMedian() {
        if (max_heap.size()>min_heap.size()){
            return max_heap.top();
        }
        if (min_heap.size()>max_heap.size()){
            return min_heap.top();
        }
        return (min_heap.top()+max_heap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */