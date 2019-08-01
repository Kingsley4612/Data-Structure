// Created by Kingsley on 2019-08-01.
// myCircularQueue

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* _cycle_array;
    int _front;
    int _rear;
    int _len;
} myCircularQueue;

myCircularQueue* myCircularQueueCreate(int k);
bool myCircularQueueEnQueue(myCircularQueue* obj, int value);
int myCircularQueueDeQueueInt(myCircularQueue* obj);
bool myCircularQueueDeQueueBool(myCircularQueue* obj);
int myCircularQueueFront(myCircularQueue* obj);
int myCircularQueueRear(myCircularQueue* obj);
bool myCircularQueueIsFull(myCircularQueue* obj);
bool myCircularQueueIsEmpty(myCircularQueue* obj);
void myCircularQueueFree(myCircularQueue* obj);

/** Set the size of the queue to be k. */
myCircularQueue* myCircularQueueCreate(int k){
    myCircularQueue* Q = malloc(sizeof(myCircularQueue));
    Q->_cycle_array = malloc(sizeof(int)*(k+1));

    Q->_front = 0;
    Q->_rear = 0;
    Q->_len = k+1;

    return Q;
}

/** Return true if the operation is successful. */
bool myCircularQueueEnQueue(myCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj))
        return false;
    obj->_cycle_array[obj->_rear] = value;
    obj->_rear++;
    if(obj->_rear == obj->_len)
        obj->_rear = 0;
    return true;
}

/** Delete an element from the circular queue. Return its value. */
int myCircularQueueDeQueueInt(myCircularQueue* obj){
    if(myCircularQueueIsFull(obj)){
        return false;
    }
    int backtrack = obj->_cycle_array[obj->_front];
    obj->_front++;
    if(obj->_front == obj->_len){
        obj->_front = 0;
    }
    return backtrack;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueueBool(myCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return false;
    obj->_front++;
    if(obj->_front == obj->_len)
        obj->_front = 0;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(myCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return -1;
    return obj->_cycle_array[obj->_front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(myCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return -1;
    else
    {
        int rear = obj->_rear;
        if(rear == 0)
            rear = obj->_len-1;
        else
            --rear;
        return obj->_cycle_array[rear];
    }
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(myCircularQueue* obj) {
    if((obj->_rear+1)%(obj->_len) == obj->_front)
        return true;
    else
        return false;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(myCircularQueue* obj) {
    if(obj->_front == obj->_rear)
        return true;
    else
        return false;
}

/** Free the circular queue. */
void myCircularQueueFree(myCircularQueue* obj) {
    free(obj->_cycle_array);
    free(obj);
}
