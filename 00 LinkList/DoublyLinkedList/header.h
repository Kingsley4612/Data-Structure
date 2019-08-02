//
// Created by Kingsley on 2019-07-25.
//

#ifndef UNTITLED17_HEADER_H
#define UNTITLED17_HEADER_H

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct LinkNode {
    int data;
    struct LinkNode* prev;
    struct LinkNode* next;
};
typedef struct LinkNode Node;

//初始化链表
Node* Init();

//遍历链表
void Foreach(Node* head);


#endif //UNTITLED17_HEADER_H
