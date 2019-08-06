//
// Created by Kingsley on 2019-07-25.
//
/* get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
 addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
 addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
 addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
 deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。 */
#include "LinkList.h"
typedef struct _Node {
    int val;
    struct _Node *prev, *next;
} Node;
typedef struct _MyLinkedList {
    Node *sen;
    int len;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList *list = (MyLinkedList *)calloc(1, sizeof (MyLinkedList));
    list->sen = (Node *)calloc(1, sizeof (Node));
    list->sen->next = list->sen->prev = list->sen;
    return list;
}

Node* _myLinkedListGetNode(MyLinkedList* obj, int index) {
    
    int i1;
    
    int rIndex = obj->len - index - 1;
    Node *getNode = NULL;
    if (rIndex > index) {
        getNode = obj->sen->next;
        for (i1 = 0; i1 < index; i1++) {
            getNode = getNode->next;
        }
    } else {
        getNode = obj->sen->prev;
        for (i1 = 0; i1 < rIndex; i1++) {
            getNode = getNode->prev;
        }
    }
    return getNode;
    
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    
    if (index >= obj->len || index < 0) {
        return -1;
    }
    
    return _myLinkedListGetNode(obj, index)->val;
    
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node *head = obj->sen;
    Node *newNode = (Node *)calloc(1, sizeof (Node));
    newNode->val = val;
    newNode->prev = head;
    newNode->next = head->next;
    head->next = head->next->prev = newNode;
    obj->len++;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node *tail = obj->sen;
    Node *newNode = (Node *)calloc(1, sizeof (Node));
    newNode->val = val;
    newNode->next = tail;
    newNode->prev = tail->prev;
    tail->prev = tail->prev->next = newNode;
    obj->len++;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    
    if (index <= 0) {
        return myLinkedListAddAtHead(obj, val);
    } else if (index == obj->len) {
        return myLinkedListAddAtTail(obj, val);
    } else if (index > obj->len) {
        return;
    }
    
    Node *afterNode = _myLinkedListGetNode(obj, index);
    Node *newNode = (Node *)calloc(1, sizeof (Node));
    newNode->val = val;
    newNode->next = afterNode;
    newNode->prev = afterNode->prev;
    afterNode->prev = afterNode->prev->next = newNode;
    obj->len++;
    
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    
    if (index >= obj->len || index < 0) {
        return;
    }
    
    int rIndex = obj->len - index - 1;
    Node *delNode = _myLinkedListGetNode(obj, index);
    delNode->next->prev = delNode->prev;
    delNode->prev->next = delNode->next;
    free(delNode);
    obj->len--;
    
}

void myLinkedListFree(MyLinkedList* obj) {
    Node *np1 = obj->sen->next;
    while (np1 != obj->sen) {
        np1 = np1->next;
        free(np1->prev);
    }
    free(obj->sen);
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
 */
