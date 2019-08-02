//
// Created by Kingsley on 2019-07-25.
//
#include "header.h"

void Foreach(Node* head){
    if(NULL== head){
        return;
    }
    //创建辅助指针
    Node* pCurrent = head->next;

    //遍历
    while (pCurrent != NULL){
        printf("%d ",pCurrent->data);
        pCurrent = pCurrent->next;
    }
    printf("\n");
}

