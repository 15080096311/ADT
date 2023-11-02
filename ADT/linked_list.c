#include<stdlib.h>
#include<stdio.h>
#ifndef List_H
    struct node;
    typedef struct node *ListNode;// 结构体指针
    typedef ListNode List; //等价于 typedef struct node *List
    typedef ListNode Position;//同上
#endif
struct node {
    int val;
    Position next;
};



int is_empty(List L ){
    return L->next ==NULL;
}
int is_last(Position P,List L){
    return P->next ==NULL;
}
Position find(int x, List L ){
    Position P;
    P=L->next;
    while(P !=NULL && P->val !=x){
        P=P->next;
    }
    return P ;
}


Position find_pre(int x, List L ){
    Position P;
    P=L->next;
    while(P->next!=NULL && P->next->val !=x){
        P=P->next;
    }
    return P ;//什么B bug  还不能找不到？
}

void delete(int x,List L){
    Position P,T;
    P=find_pre(x,L);
    if(!is_last(P,L)){
        T = P->next;
        P->next = T->next; //自己画图理解
        free(T);
    }
}

void insert(int x,List L ,Position P){
    Position T;
    T=malloc(sizeof(List));
    if(T==NULL){
        FatalError("插入空节点");
    }
    T->val = x;
    T->next =P->next;
    P->next =T;
}
int main(){
    List  head = NULL,  tail = NULL;
    head = tail = malloc(sizeof (List ));
    for(int i =0 ;i<2;i++){
        tail ->next =malloc(sizeof (List));
        tail  =tail ->next;
        int x=0;
        scanf("%d",&x);
        tail->val= x; 
    }
    system("pause");
    return 0;

}