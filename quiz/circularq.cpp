#include <iostream>
using namespace std;

#define SIZE 5

struct Queue{
    int items[SIZE], front, rear;
};
using queue= Queue *;

queue newQueue(){
    queue q =new Queue;
    q->front = -1;
    q->rear= -1;
    return q;
}

bool full(queue q){
    if(q->front==0 &&q->rear==SIZE-1) return true;
    if(q->front==q->rear+1) return true;
    return false;
}

bool empty(queue q){
    if(q->front==-1)return true;
    return false;
}

void enqueue(queue q, int element){
    cout<< "Try to enqueue: " << element<<endl;
    if(full(q)) cout<<"Queue is full"<<endl;
    else{
        if(q->front==-1) q->front=0;
        q->rear=(q->rear+1)%SIZE;
        q->items[q->rear]=element;
        cout << "enqueued: " << element <<endl;
    }
}

int dequeue(queue q){
    cout<< "Try to dequeue" <<endl;
    int element;
    if(empty(q)){
        cout<< "Queue is empty" <<endl;
        return(-1);
    }
    else{
        element = q->items[q->front];
        if(q->front==q->rear){
            q->front=-1;
            q->rear=-1;
        }
        else{
            q->front=(q->front+1)%SIZE;
        }
    }
    return element;
}

void display(queue q){
    int i;
    if(empty(q)) cout << endl << "Empty Queue" << endl;
    else{
        cout << "Front[" << q->front <<"]\n";
        cout << "Items: ";
        for(i=q->front; i!=q->rear;i=(i+1)%SIZE) cout<< q->items[i] << ' ';
        cout << q->items[i];
        cout << endl << " Rear[" << q->rear << "]\n";
    }
    cout<<endl;
}

int main(){
    queue q=newQueue();
    dequeue(q);
    display(q);
    enqueue(q,1);
    display(q);
    enqueue(q,2);
    display(q);
    enqueue(q,3);
    display(q);
    enqueue(q,4);
    display(q);
    enqueue(q,5);
    display(q);
    enqueue(q,6);
    display(q);
    int elem=dequeue(q);
    if(elem!=-1) cout << "dequeued: " << elem << endl;
    display(q);
    enqueue(q,7);
    display(q);
    enqueue(q,8);
    display(q);
    elem=dequeue(q);
    if(elem!=-1) cout << "dequeued: " << elem << endl;
    display(q);
    elem=dequeue(q);
    if(elem!=-1) cout << "dequeued: " << elem << endl;
    display(q);
    return 0;
}