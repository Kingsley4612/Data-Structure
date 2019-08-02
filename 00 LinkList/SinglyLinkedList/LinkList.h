//
// Created by Kingsley on 2019-07-25.
//

#ifndef UNTITLED16_LINKLIST_H
#define UNTITLED16_LINKLIST_H
#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

//定义节点数据类型
struct LinkNode{
    int data;
    struct LinkNode* next;
};
typedef struct LinkNode Node;

//初始化链表
Node* Init();

//在值为old_value的后面插入一个new_value
void InsertByValue(Node* header,int old_value,int new_value);

//删除值为value的节点
void RemoveByValue(Node* header,int delete_value);

//遍历
void Foreach(Node* header);

//销毁链表
void Destory_(Node* header);

//清空链表
void Clear(Node* header);

//逆序链表
void Reverse(Node* header);

//测试
void test01();

//排序
Node *SelectSort(Node *header);

#endif //UNTITLED16_LINKLIST_H
