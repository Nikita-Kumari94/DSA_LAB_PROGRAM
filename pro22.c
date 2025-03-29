#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};


struct node * create(int x) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

bool cylclecheck(struct node *head) {
    if (head == NULL || head->next == NULL)
        return false;

    struct node *slow = head;
    struct node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

void remove_cycle(struct node *head) {
    if (head == NULL || head->next == NULL)
        return;

    struct node *slow = head;
    struct node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (slow == fast) {
        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}

void print(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = create(5);
    head->next = create(4);
    head->next->next = create(11);
    head->next->next->next = create(2);
    head->next->next->next->next = create(7);
    head->next->next->next->next->next = create(9);
    head->next->next->next->next->next->next = head->next;

    if (cylclecheck(head)) {
        printf("Cycle is present in Linked list");
        remove_cycle(head);
        printf("\nCycle removed...");
    } else {
        printf("\nLinked list does not have a cycle.");
    }

    printf("\nLinked list after cycle removal:\n");
    print(head);

    return 0;
}
