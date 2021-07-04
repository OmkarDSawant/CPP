#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
    vector<int> items;

    int getLeftChildIndex(int parentIndex)
    {
        return ((2 * parentIndex) + 1);
    }

    int getRightChildIndex(int parentIndex)
    {
        return ((2 * parentIndex) + 2);
    }

    int getParentIndex(int childIndex)
    {
        return ((childIndex - 1) / 2);
    }

    bool hasLeftChild(int index)
    {
        return (getLeftChildIndex(index) < items.size());
    }

    bool hasRightChild(int index)
    {
        return (getRightChildIndex(index) < items.size());
    }

    bool hasParent(int index)
    {
        return (getParentIndex(index) >= 0);
    }

    int leftChildValue(int index)
    {
        return (items[getLeftChildIndex(index)]);
    }

    int rightChildValue(int index)
    {
        return (items[getRightChildIndex(index)]);
    }

    int parentValue(int index){
        return (items[getParentIndex(index)]);
    }

    void swap(int indexOne, int indexTwo){
        int temp = items[indexOne];
        items[indexOne] = items[indexTwo];
        items[indexTwo] = temp;
    }

    public:

    void heapifyUp(){
        int index = (items.size()-1);

        while(hasParent(index) && parentValue(index) > items[index]){
            swap(getParentIndex(index),index);
            index = getParentIndex(index); //move up
        }
    }

    void heapifyDown(){
        int index = 0;

        while(hasLeftChild(index)){ //If no left child then certainly no right child.

            int smallerIndex = getLeftChildIndex(index);

            if(hasRightChild(index) && rightChildValue(index) < leftChildValue(index)){
                smallerIndex = getRightChildIndex(index);
            }

            if(items[index] > items[smallerIndex]){
                swap(index, smallerIndex);
                index = smallerIndex; //move down
            }else{
                break;
            }
        }
    }

    int peek(){ //Returns the element at the top.
        if(items.size() == 0){
            return -1;
        }
        return items[0];
    }

    int poll(){ //Deletion from root.
        if(items.size() == 0){
            return -1;
        }
        int item = items[0];
        items[0] = items[(items.size()-1)];
        items.pop_back(); //To shrink.

        heapifyDown();

        return item;
    }

    void add(int item){ //Insertion from leaf.
        items.push_back(item);

        heapifyUp();
    }

};

int main()
{
    MinHeap m1;
    m1.add(5);
    m1.add(9);
    m1.add(13);
    m1.add(3);
    m1.add(1);

    cout<<"Minimum element: "<<m1.peek()<<"\n";

    cout<<"Element Deleted: "<<m1.poll()<<"\n";

    cout<<"Minimum element: "<<m1.peek()<<"\n";

    return 0;
}