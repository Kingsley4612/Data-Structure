//
//  Polynomial.h
//  Polynomial2.0
//
//  Created by Kingsley on 2019/9/24.
//  Copyright © 2019 Kingsley. All rights reserved.
//

#ifndef Polynomial_h
#define Polynomial_h

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

//数据

typedef struct{         //多项式的项
    float coef;         //系数
    int   expn;         //指数
}ElemType;              //重定义线性表中的元素类型

typedef struct Node{    //结点类型
    ElemType data;
    struct Node* next;
}Node;

typedef Node* Link;     //指向结构的指针
typedef Node* PositionPtr;

typedef struct{         //链表类型
    Link head;          //指向线性链表的头部
    Link tail;          //指向线性链表的尾部
    int len;            //数据元素的个数
}LinkList;

typedef LinkList Polynomial;

//功能

int MakeNode(Link *p, ElemType e);

void FreeNode(Link *p);

int InitList(LinkList* L);

void ClearList(LinkList* L);

void DestoryList(LinkList* L);

void InsFirst(LinkList* L, Link h, Link s);

int DelFirst(LinkList* L, Link h, Link* q);

void Append(LinkList* L, Link s);

void SetCurElem(Link p, ElemType e);

ElemType GetCurElem(Link p);

int ListLength(LinkList L);

PositionPtr GetHead(LinkList L);

PositionPtr GetLast(LinkList L);

PositionPtr NextPos(Link p);



void CreatPolyn(FILE* fp, Polynomial* P, int m);

void DestroyPolyn(Polynomial* P);

void PrintPolyn(Polynomial P);

int PolynLength(Polynomial P);

void AddPolyn(Polynomial* Pa, Polynomial* Pb);

int Cmp(ElemType c1, ElemType c2);

#endif /* Polynomial_h */
