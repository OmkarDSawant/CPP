#include<iostream>
#include<queue>

using namespace std;

priority_queue <int, vector<int>> maxHeap;
priority_queue <int, vector<int>, greater<int>> minHeap;

void insert(int x){

    if(maxHeap.size() == minHeap.size()){
        if(maxHeap.size() == 0){
            maxHeap.push(x);
        }
        else{
            if(x > maxHeap.top()){
                minHeap.push(x);
            }else{
                maxHeap.push(x);
            }
        }
    }
    else if(maxHeap.size() > minHeap.size()){
        if(x > maxHeap.top()){
            minHeap.push(x);
        }else{
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
            maxHeap.push(x);
        }
    }
    else{
        if(x < minHeap.top()){
            maxHeap.push(x);
        }else{
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
            minHeap.push(x);
        }
    }
}

double findMedian(){
    if(maxHeap.size() == minHeap.size()){
        return (maxHeap.top() + minHeap.top())/2.0;
    }else if(maxHeap.size() > minHeap.size()){
        return maxHeap.top();
    }
    return minHeap.top();
}

int main(){
    
    insert(10);
    cout<<findMedian()<<"\n";

    insert(15);
    cout<<findMedian()<<"\n";

    insert(21);
    cout<<findMedian()<<"\n";

    insert(30);
    cout<<findMedian()<<"\n";

    insert(18);
    cout<<findMedian()<<"\n";

    insert(19);
    cout<<findMedian()<<"\n";
    return 0;
}