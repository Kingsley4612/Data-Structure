/** 栈的链式存储结构 */
/** 把栈顶放在单链表的头部。由于有了栈顶在头部，单链表的头节点也就失去了意义，所以对于栈链来说，是不需要头结点的 */
/** 栈链不存在栈满的情况，空栈：top = NULL；*/
typedef int Status;
typedef int SElemType;
typedef struct {
    SElemType data;
    struct StackNode* next;
}StackNode;

typedef struct {
    StackNode* top;
    int count;
}LinkStack;

/** 插入元素e为新的栈顶元素 */
bool Push(LinkStack* S,SElemType e){
    StackNode* New = malloc(sizeof(StackNode));
    New->data = e;
    New->next = S->top;
    S->top = New;
    S->count++;
    return true;
}

/** 推出栈顶元素 用e返回 */
Status Pop(LinkStack* S){
    if(S->top == NULL){
        return false;
    }
    int e = S->top->data;
    StackNode* p =S->top;
    S->top = p->next;
    free(p);
    S->count--;
    return e;
}
