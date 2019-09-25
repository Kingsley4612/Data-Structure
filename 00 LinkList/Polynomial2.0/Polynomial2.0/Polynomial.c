//
//  Polynomial.c
//  Polynomial2.0
//
//  Created by Kingsley on 2019/9/24.
//  Copyright © 2019 Kingsley. All rights reserved.
//

#include "Polynomial.h"

int MakeNode(Link *p, ElemType e){
    *p = (Link)malloc(sizeof(Node));
    if(!(*p)){
        exit(OVERFLOW);
    }
    
    (*p)->data = e;
    (*p)->next = NULL;
    
    return OK;
}

void FreeNode(Link *p){
    free(*p);
    *p = NULL;
}

int InitList(LinkList* L){
    Link p;
    
    p = (Link)malloc(sizeof(Node));
    if(!p)
        exit(OVERFLOW);
    p->next = NULL;
    
    (*L).head = (*L).tail = p;
    (*L).len = 0;
    
    return OK;
}

void ClearList(LinkList *L){
    Link p, q;

    p = (*L).head->next;

    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }

    (*L).head->next = NULL;
    (*L).tail = (*L).head;
    (*L).len = 0;
}

void DestroyList(LinkList *L){
    ClearList(L);

    free((*L).head);

    (*L).head = (*L).tail = NULL;
}


void InsFirst(LinkList *L, Link h, Link s){
    s->next = h->next;
    h->next = s;

    if(h==(*L).tail)            //若h为尾结点
        (*L).tail = h->next;

    (*L).len++;
}

int DelFirst(LinkList *L, Link h, Link *q){
    *q = h->next;
    
    if(*q){                     //链表非空
        h->next = (*q)->next;
        if(!h->next)            //h后只有一个结点
            (*L).tail = h;
        
        (*L).len--;             //并不释放被删结点所占空间
        return OK;
    }
    return ERROR;
}

void Append(LinkList *L, Link s){
    int count = 0;

    (*L).tail->next = s;

    while(s)                    //考虑s为空的情况
    {
        (*L).tail = s;
        s = s->next;
        count++;
    }

    (*L).len += count;
}


void SetCurElem(Link p, ElemType e){
    p->data = e;
}

ElemType GetCurElem(Link p){
    return p->data;
}

int ListLength(LinkList L){
    return L.len;
}

PositionPtr GetHead(LinkList L){
    return L.head;
}

PositionPtr GetLast(LinkList L){
    return L.tail;
}

PositionPtr NextPos(Link p){
    return p->next;
}


void CreatPolyn(FILE* fp, Polynomial* P, int m){
    PositionPtr h;
    ElemType e;
    int i;
    Link p;

    InitList(P);            //初始化一个扩展的单链表存放多项式
    h = GetHead(*P);          //获取多项式头指针

    e.coef = 0.0;
    e.expn = -1;
    SetCurElem(h, e);           //设置头结点的数据元素
    h->next = NULL;
    
    for(i=1; i<=m; i++){         //依次录入n个非0项
        fscanf(fp, "%f %d", &(e.coef), &(e.expn));
        MakeNode(&p, e);
        p->next = NULL;
        InsFirst(P, h, p);
        h = h->next;
    }
}

void DestroyPolyn(Polynomial *P){
    DestroyList(P);
}


void PrintPolyn(Polynomial P){
    int i;
    Link p;

    p = P.head->next;
    for(i=1; i<=P.len; i++){
        if(i==1)
            printf("%g", p->data.coef);
        else{
            if(p->data.coef>0){
                printf(" + ");
                printf("%g", p->data.coef);
            }
            else{
                printf(" - ");
                printf("%g", -p->data.coef);
            }
        }

        if(p->data.expn){
            printf("x");

            if(p->data.expn!=1)
                printf("^%d", p->data.expn);
        }
        p = p->next;
    }
}

int PolynLength(Polynomial P){
    return ListLength(P);
}

void AddPolyn(Polynomial *Pa, Polynomial *Pb){
    PositionPtr ha, hb;
    PositionPtr qa, qb;
    ElemType a, b;
    float sum;

    ha = GetHead(*Pa);          //ha、hb分别指向Pa、Pb头结点
    hb = GetHead(*Pb);
    qa = NextPos(ha);           //qa、qb分别指向Pa、Pb的当前结点
    qb = NextPos(hb);

    while(qa && qb){             //qa、qb均非空
        a = GetCurElem(qa);       //a和b为两表中当前比较元素
        b = GetCurElem(qb);

        switch(Cmp(a,b)){        //比较当前元素的指数大小
            case -1:            //多项式Pa中当前结点的指数值较小
                ha = qa;
                qa = NextPos(ha);
                break;
                
            case 0:             //两者数值相等
                sum = a.coef + b.coef;
                if(sum != 0.0){        //相加不能抵消时更新Pa结点的系数值
                    qa->data.coef = sum;
                    SetCurElem(qa, qa->data);
                    ha = qa;        //此时ha需后移
                }
                else{            //相加抵消时，删除Pa中当前结点
                    DelFirst(Pa, ha, &qa);
                    FreeNode(&qa);
                }
                DelFirst(Pb, hb, &qb);  //删除Pb中扫描过的结点
                FreeNode(&qb);
                qb = NextPos(hb);     //qa、qb均后移
                qa = NextPos(ha);
                break;
                
            case 1:             //多项式Pb中当前结点的指数值较小
                DelFirst(Pb, hb, &qb);  //摘下Pb当前结点
                InsFirst(Pa, ha, qb);   //将摘下结点链入Pa中
                qb = NextPos(hb);
                ha = NextPos(ha);
                break;
                
        }//switch
    }//while

    if(qb)                  //若Pb还未扫描完，将剩余项链接到Pa后
        Append(Pa, qb);

    FreeNode(&hb);            //释放Pb头结点
    (*Pb).head = (*Pb).tail = NULL;     //设置Pb为销毁状态
    (*Pb).len = 0;
}

int Cmp(ElemType c1, ElemType c2){
    int i = c1.expn - c2.expn;

    if(i<0)
        return -1;
    else if(i==0)
        return 0;
    else
        return 1;
}
