#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>


using namespace std;

template<class T>
class PQNode
{
    public:
        T data;
        int priority;

        PQNode(T Data) {
            data = Data;
            priority = 1;
        }
    
        PQNode(T Data, int Priority) {
            data = Data;
            if (Priority < 1)
                Priority = 1;
            priority = Priority;
        }
};


template<class T>
class PriorityQueue
{
    private:
        vector<PQNode<T>> queue; // The vector holding all of the items in the queue.

    public:
        // Constructors and Destructor
        PriorityQueue();
        PriorityQueue(const PriorityQueue &obj);
        ~PriorityQueue();
        
        // Acessors and Mutators
        void enqueue(T Data, int Priority = 1);
        T dequeue();
        
        // Other Functions
        void print();
        bool isEmpty();
        void clear();
        int size();
};


template<class T>
PriorityQueue<T>::PriorityQueue()
{
    //Nothing needed in constructor
    //vectors do not need to be initialized
}

template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue &obj)
{
    queue.swap(obj.queue);
}

template<class T>
PriorityQueue<T>::~PriorityQueue()
{
    //Nothing needed in Destructor
}

template<class T>
void PriorityQueue<T>::enqueue(T Data, int Priority)
{
    PQNode<T> newNode(Data, Priority);
    queue.push_back(newNode);
}

template<class T>
T PriorityQueue<T>::dequeue()
{
    T val;
    if(isEmpty())
        return val;
    else{
        int top = queue.at(0).priority;
        for(int i=0; i<queue.size(); i++)
        {
            if(queue.at(i).priority > top)
                top = queue.at(i).priority;
        }

        PriorityQueue<T> vect;
        while(!isEmpty() && top!=0)
        {
            for(int i=0; i<queue.size(); i++)
            {
                if(queue.at(i).priority == top)
                    vect.queue.push_back(queue.at(i));
            }
            top--;
        }

        queue.swap(vect.queue);
        val = queue.front().data;
        queue.erase(queue.begin());
        return val;
    }
}

template<class T>
void PriorityQueue<T>::print()
{
    for(int i=0; i<queue.size(); i++)
        cout << queue.at(i).data << "  ---  " << queue.at(i).priority << endl;
}

template<class T>
bool PriorityQueue<T>::isEmpty()
{
    if(queue.size() == 0)
        return true;
    else
        return false;
}

template<class T>
void PriorityQueue<T>::clear()
{
    queue.clear();
}

template<class T>
int PriorityQueue<T>::size()
{
    return queue.size();
}



#endif