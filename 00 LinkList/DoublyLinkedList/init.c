//
// Created by Kingsley on 2019-07-25.
//
#include "header.h"

Node* Init(){
    //创建头结点
    Node* head = malloc(sizeof(Node));
    head->data = 24;
    head->next = NULL;
    head->prev = NULL;

    //创建尾部指针
    Node* pRear = head;
    int val = 24;
    //计数器
    int counter = 0;

    while (true){
        //数据输入
        printf("请输入数据(输入-1时结束)：");
        scanf("%d",&val);
        if(val==-1){
            break;
        }
        //创建新结点
        Node* newnode = malloc(sizeof(Node));
        //输入数据到结点
        newnode->data = val;
        //结点插入链表
        newnode->next = NULL;
        newnode->prev = pRear;
        pRear->next = newnode;
        pRear = newnode;
        counter++;
    }
    printf("共输入了%d个数据结点\n",counter);
    return head;

}


