

#ifndef LISTS
#define LISTS

#include <stddef.h>

typedef struct{
    char name[80];
    int grade;
}elem;


typedef struct ListNode {
    elem data;
    struct ListNode *next;
} ListNode, *ListNodePtr;


void LL_INIT(ListNodePtr* head);
int LL_EMPTY(ListNodePtr head);
elem LL_DATA(ListNodePtr p);
int LL_INSERT_START(ListNodePtr *head, elem x);
int LL_INSERT_AFTER(ListNodePtr p, elem x);
int LL_DELETE_START(ListNodePtr *head, elem *x);
int LL_DELETE_AFTER(ListNodePtr prev, elem *x);
void LL_PRINT(ListNodePtr head);
void LL_DESTROY(ListNodePtr *head);
ListNodePtr LL_MERGE(ListNodePtr list1, ListNodePtr list2);
void LL_SPLIT(ListNodePtr* source, ListNodePtr* front, ListNodePtr* back);
void LL_MERGESORT(ListNodePtr* head);
void LL_AVERAGE(ListNodePtr head);
int LL_REVERCE(ListNodePtr* head);
void LL_COPY(ListNodePtr source, ListNodePtr* destination);
int LL_DUB(ListNodePtr *head);



#endif

