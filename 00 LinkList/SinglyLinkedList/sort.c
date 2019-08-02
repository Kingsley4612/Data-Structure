//
// Created by Kingsley on 2019-07-25.
//
/*

 选择排序的基本思想就是反复从还未排好序的那些节点中，
 选出键值最小的节点，
 依次重新组合成一个链表。

 写链表这类程序，关键是理解：
 head存储的是第一个节点的地址，head->next存储的是第二个节点的地址；
 任意一个节点p的地址，只能通过它前一个节点的next来求得。

单向链表的选择排序图示：
---->[1]---->[3]---->[2]...----> [n]---->[NULL]（原链表）
head   1->next  3->next  2->next   n->next

---->[NULL]（空链表）
first
tail
---->[1]---->[2]---->[3]...---->[n]---->[NULL]（排序后链表）
first   1->next  2->next  3->next   tail->next

1、先在原链表中找最小的，找到一个后就把它放到另一个空的链表中；
2、空链表中安放第一个进来的节点，产生一个有序链表,并且让它在原链表中分离出来（此时要注意原链表中出来的是第一个节点还是中间其它节点）；
3、继续在原链表中找下一个最小的，找到后把它放入有序链表的尾指针的next,然后它变成其尾指针；
*/
#include "LinkList.h"

Node *SelectSort(Node* header)
{
    Node *pfirst;      /* 排列后有序链的表头指针 */
    Node *ptail;       /* 排列后有序链的表尾指针 */
    Node *pminBefore;  /* 保留键值更小的节点的前驱节点的指针 */
    Node *pmin;        /* 存储最小节点   */
    Node *p;           /* 当前比较的节点 */

    pfirst = NULL;

    Node* fakehead = header->next;
    while (fakehead != NULL)         /*在链表中找键值最小的节点。*/
    {
        /* 注意：这里for语句就是体现选择排序思想的地方 */
        for (p = fakehead, pmin = fakehead; p->next != NULL; p = p->next) /*循环遍历链表中的节点，找出此时最小的节点。*/
        {
            if (p->next->data < pmin->data) /*找到一个比当前min小的节点。*/
            {
                pminBefore = p;           /*保存找到节点的前驱节点：显然p->next的前驱节点是p。*/
                pmin = p->next;     /*保存键值更小的节点。*/
            }
        }

        /*上面for语句结束后，就要做两件事；一是把它放入有序链表中；二是根据相应的条件判断，安排它离开原来的链表。*/

        /*第一件事*/
        if (pfirst == NULL)     /* 如果有序链表目前还是一个空链表                      */
        {
            pfirst = pmin;      /* 第一次找到键值最小的节点。                          */
            ptail  = pmin;      /* 注意：尾指针让它指向最后的一个节点。                */
        }
        else                    /* 有序链表中已经有节点                                */
        {
            ptail->next = pmin; /* 把刚找到的最小节点放到最后，即让尾指针的next指向它。*/
            ptail = pmin;       /* 尾指针也要指向它。                                  */
        }

        /*第二件事*/
        if (pmin == fakehead)        /* 如果找到的最小节点就是第一个节点                    */
        {
            fakehead = fakehead->next;   /* 显然让head指向原head->next,即第二个节点，就OK       */
        }
        else /*如果不是第一个节点*/
        {
            pminBefore->next = pmin->next; /*前次最小节点的next指向当前pmin的next,这样就让pmin离开了原链表。*/
        }
    }

    if (pfirst != NULL)     /*循环结束得到有序链表first                */
    {
        ptail->next = NULL; /*单向链表的最后一个节点的next应该指向NULL */
    }
    header->next = pfirst;
    return header;
}
