#include "lists.h"
#include <stdio.h>
#include <stdlib.h>


void LL_INIT(ListNodePtr *head) {
    *head = NULL;
}

int LL_EMPTY(ListNodePtr head) {
    return head == NULL;
}

elem LL_DATA(ListNodePtr p) {
    return p->data;
}

int LL_INSERT_START(ListNodePtr *head, elem x) {
    ListNodePtr newnode;

    newnode = malloc(sizeof(ListNode));

    if (!newnode) {
        printf("Couldn't allocate space!\n");
        return 1;
    }

    newnode->data = x;
    newnode->next = *head;
    *head = newnode;
    return 0;
}

int LL_INSERT_AFTER(ListNodePtr p, elem x) {
    ListNodePtr newnode;

    newnode = malloc(sizeof(ListNode));

    if (!newnode) {
        printf("Couldn't allocate space!\n");
        return 1;
    }

    newnode->data = x;
    newnode->next = p->next;
    p->next = newnode;
    return 0;
}

int LL_DELETE_START(ListNodePtr *head, elem *x){
    ListNodePtr current;
    if(*head==NULL){
        return 1;
    }

    current=*head;

    *x=current->data;

    (*head)=(*head)->next;

    free(current);
    return 0;

}



int LL_DELETE_AFTER(ListNodePtr prev, elem *x){
    ListNodePtr current;

    if(prev->next==NULL){
        return 1;
    }

    current=prev->next;
    *x=current->data;
    prev->next=current->next;
    free(current);
    return 0;
}

void LL_PRINT(ListNodePtr head) {
    ListNodePtr current = head;

    while (current != NULL) {
        printf("(%s, %d)", current->data.name, current->data.grade);

        current = current->next;

        if (current != NULL) {
            printf(", ");
        }
    }

    printf(".\n");
}


void LL_DESTROY(ListNodePtr *head) {
    ListNodePtr ptr;

    while (*head != NULL) {
        ptr = *head;
        *head = (*head)->next;
        free(ptr);
    }
}

ListNodePtr LL_MERGE(ListNodePtr list1, ListNodePtr list2) {
    ListNodePtr result = NULL;

    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    }

    if (list1->data.grade >= list2->data.grade) {
        result = list1;
        result->next = LL_MERGE(list1->next, list2);
    } else {
        result = list2;
        result->next = LL_MERGE(list1, list2->next);
    }


    return result;
}

void LL_SPLIT(ListNodePtr* source, ListNodePtr* front, ListNodePtr* back) {
    ListNodePtr fast, slow;
    slow = *source;
    fast = (*source)->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    *front = *source;
    *back = slow->next;
    slow->next = NULL;
}

void LL_MERGESORT(ListNodePtr* head){

    ListNodePtr current, list1,list2;

    current = *head;

    if(current == NULL || current->next == NULL){
        return;
    }


    LL_SPLIT(&current,&list1,&list2);

    LL_MERGESORT(&list1);
    LL_MERGESORT(&list2);

    *head = LL_MERGE(list1,list2);

}
void LL_AVERAGE(ListNodePtr head) {
    ListNodePtr current;
    int sum = 0, cnt = 0;
    double average;

    current = head;

    while (current != NULL) {
        sum += current->data.grade;
        cnt += 1;
        current = current->next;
    }

    if (cnt != 0) {
        average = (double)sum / cnt;
        printf("Average: %.2lf\n", average);
    } else {
        printf("The list is empty.\n");
    }
}


int LL_REVERCE(ListNodePtr* head){
    if(*head==NULL){
        return 1;
    }

    ListNodePtr current = *head;
    ListNodePtr prev=NULL, next;

    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }

   *head=prev;

    return 0;

}

void LL_COPY(ListNodePtr source, ListNodePtr* destination){
    *destination = NULL;

    while(source!=NULL){
        LL_INSERT_START(destination,source->data);
        source=source->next;
    }


    LL_REVERCE(destination);

}


int LL_DUB(ListNodePtr *head){
    ListNodePtr current;

    current=*head;

    while (current != NULL) {
        ListNodePtr runner = current;

        while (runner->next != NULL) {
            if (runner->next->data.grade == current->data.grade) {
                LL_DELETE_AFTER(runner, &current->data);
                printf("Dublicated numbers found!\n");
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }


    return 0;
}
