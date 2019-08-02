//
// Created by Kingsley on 2019-07-25.
//
#include "LinkList.h"

Node* Init(){
    //创建头结点
    Node* header = malloc(sizeof(Node));
    header->data = -1;
    header->next = NULL;

    //创建尾部指针
    Node* pRear = header;
    int val = -1;
    int counter = 0;
    while (true){
        printf("请输入数据(输入-1时结束)：");
        scanf("%d",&val);
        if(val==-1){
            break;
        }
        //创建新结点
        Node* newnode = malloc(sizeof(Node));
        newnode->data = val;
        newnode->next = NULL;
        //新结点插入链表中
        pRear->next = newnode;
        //更新尾部指针指向
        pRear = newnode;
        counter++;
    }
    printf("共输入了%d个数据结点\n",counter);
    return header;
}

void InsertByValue(Node* header,int old_value,int new_value){
    if(header == NULL){
        return;
    }
    //两个辅助指针变量
    Node* pPrevious = header;
    Node* pCurrent = pPrevious->next;

    while (pCurrent!=NULL){
        if(pCurrent->data == old_value){
            break;
        }
        pPrevious = pCurrent;
        pCurrent = pCurrent->next;
    }
    if(pCurrent== NULL){
        printf("链表中无此old_value,因此无法插入\n");
        return;
    }
    //先为new_value创建结点
    Node* newNode = malloc(sizeof(Node));
    newNode->data = new_value;

    //插入
    newNode->next = pCurrent;
    pPrevious->next = newNode;
}


void RemoveByValue(Node* header,int delete_value){
    if(header ==NULL){
        return;
    }
    //两个辅助指针
    Node*pPrivous = header;
    Node*pCurrent = header->next;

    while (pCurrent!=NULL) {
        if (pCurrent->data == delete_value) {
            //删除
            pPrivous->next = pCurrent->next;
            free(pCurrent);
            return;
        }
        pPrivous = pCurrent;
        pCurrent = pCurrent->next;
    }
    printf("未找到要删除的数据\n");
}

void Foreach(Node* header){
    if(NULL== header){
        return;
    }
    Node* pCurrent = header->next;
//    Node* pCurrent = header;
    while (pCurrent != NULL){
        printf("%d ",pCurrent->data);
        pCurrent = pCurrent->next;
    }
    printf("\n");
}

//销毁链表
void Destory_(Node* header){
    if(header == NULL){
        return;
    }
    //辅助指针
    Node* pCurrent = header;
    while (pCurrent != NULL){
        //保存下一个结点的地址
        Node* pNext = pCurrent->next;
        //释放当前结点内存
        free(pCurrent);
        pCurrent = pNext;
    }
    printf("销毁完成\n");
}

void Clear(Node* header){
    if(header==NULL){
        return;
    }
    //辅助指针变量
    Node* pCurrent = header->next;
    while (pCurrent!=NULL){
        //先保存当前结点的下一个结点地址
        Node* pNext = pCurrent->next;
        //释放当前结点内存
        free(pCurrent);
        //释放
        pCurrent = pNext;
    }
    header->next = NULL;
    printf("清空完成\n");
}

void Reverse(Node* header){
    if(header == NULL){
        return;
    }
    //创建三个复制指针
    Node* pPrivous = NULL;
    Node* pCurrent = header->next;
    Node* pNext = NULL;

    while (pCurrent != NULL){
        pNext = pCurrent->next;
        pCurrent->next = pPrivous;
        pPrivous = pCurrent;
        pCurrent = pNext;
    }
    header->next = pPrivous;


}
