#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Stack *
 *
 * Functions:
 * - create
 * - clear
 * - isEmpty
 * - isFull
 * - count
 * - print - Print all elements
 * - peek  - Get first element without popping
 * - push 
 * - pop
 *
 * top = first available position
 */

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} LinkedStack;

void print_stack(LinkedStack* stack);

void push(LinkedStack* pStack, int value);
short int is_empty(LinkedStack* pStack);
short int peek(LinkedStack* pStack, int* ret_value);
short int pop(LinkedStack* pStack, int* ret_value);
void clear(LinkedStack* pStack);

int main(void) {
    LinkedStack stack = { NULL };
    for(int i = 0; i < 10; i++) {
        push(&stack, i);
    }
    print_stack(&stack);

    int ret_val;
    for(int i = 0; i < 5; i++) {
        int wasPopped = pop(&stack, &ret_val);

        if(!wasPopped) {
            printf("error: cannot pop an element from an empty stack\n");
            continue;
        }

        printf("Popped: %d\n", ret_val);
    }
    printf("After popping: \n");
    print_stack(&stack);

    if(peek(&stack, &ret_val)) {
        printf("Peeked: %d\n", ret_val);
    }

    printf("After peeking: \n");
    print_stack(&stack);

    clear(&stack);

    return 0;
}

void print_stack(LinkedStack* pStack) {
    Node* p = pStack->top;
    printf("\n");
    while(p != NULL) {
        printf("# % 10d #\n", p->data);
        p = p->next;
    }
    printf("##############\n\n");
}

void push(LinkedStack* pStack, int value) {
    Node* new = malloc(sizeof(*new));
    new->data = value;

    new->next = pStack->top;
    pStack->top = new;
}

short int is_empty(LinkedStack* pStack) {
    return pStack->top == NULL;
}

short int peek(LinkedStack* pStack, int* ret_value) {
    if(is_empty(pStack)) return 0;

    *ret_value = pStack->top->data;
    return 1;
}

short int pop(LinkedStack* pStack, int* ret_value) {
    if(is_empty(pStack)) return 0;

    Node* to_pop = pStack->top;
    pStack->top = to_pop->next;

    *ret_value = to_pop->data;
    free(to_pop);
    return 1;
}

void clear(LinkedStack* pStack) {
    while(pStack->top != NULL) {
        Node* next = pStack->top->next;
        free(pStack->top);
        pStack->top = next;
    }
}
