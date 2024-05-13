/*

        Problem Statement:
                Min/max Heaps:  Marks obtained by students of second year in an
                                online examination of a particular subject are stored by the teacher.
                                Teacher wants to find the minimum and maximum marks of the subject.
                                Write a menu driven C++ program to find out maximum and minimum
                                marks obtained in that subject using heap data structure. Analyze the
                                algorithm
*/

#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
private:
    vector<int> heap;

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parentIndex = (index - 1) / 2;
            if (heap[parentIndex] > heap[index])
            {
                swap(heap[parentIndex], heap[index]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyDown(int index)
    {
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
        {
            smallest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
        {
            smallest = rightChild;
        }

        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin()
    {
        if (heap.empty())
        {
            cout << "Heap is empty.\n";
            return -1; // or throw an exception
        }

        int minValue = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minValue;
    }
};

class MaxHeap
{
private:
    vector<int> heap;

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parentIndex = (index - 1) / 2;
            if (heap[parentIndex] < heap[index])
            {
                swap(heap[parentIndex], heap[index]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyDown(int index)
    {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest])
        {
            largest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] > heap[largest])
        {
            largest = rightChild;
        }

        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax()
    {
        if (heap.empty())
        {
            cout << "Heap is empty.\n";
            return -1; // or throw an exception
        }

        int maxValue = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxValue;
    }
};

int main()
{
    vector<int> marks;
    MinHeap minHeap;
    MaxHeap maxHeap;
    int choice, mark;

    do
    {
        cout << "1. Add mark\n";
        cout << "2. Find minimum and maximum marks\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter mark: ";
            cin >> mark;
            marks.push_back(mark);
            minHeap.insert(mark);
            maxHeap.insert(mark);
            break;
        case 2:
            if (marks.empty())
            {
                cout << "No marks entered yet.\n";
            }
            else
            {
                cout << "Minimum mark: " << minHeap.extractMin() << endl;
                cout << "Maximum mark: " << maxHeap.extractMax() << endl;
            }
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

/*
OUTPUT:-
1. Add mark
2. Find minimum and maximum marks
3. Exit
Enter your choice: 1
Enter mark: 98
1. Add mark
2. Find minimum and maximum marks
3. Exit
Enter your choice: 1
Enter mark: 87
1. Add mark
2. Find minimum and maximum marks
3. Exit
Enter your choice: 1
Enter mark: 90
1. Add mark
2. Find minimum and maximum marks
3. Exit
Enter your choice: 1
Enter mark: 99
1. Add mark
2. Find minimum and maximum marks
3. Exit
Enter your choice: 2
Minimum mark: 87
Maximum mark: 99
1. Add mark
2. Find minimum and maximum marks
3. Exit
Enter your choice: 3
Exiting program.
*/