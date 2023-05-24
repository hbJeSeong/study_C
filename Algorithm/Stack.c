#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* newStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot pop\n");
        return -1;
    }
    int poppedValue = stack->top->value;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, nothing to peek\n");
        return -1;
    }
    return stack->top->value;
}

void deleteNode(Node* node) {
    node->next = NULL;
    free(node);
}

void deleteStack(Stack* stack) {
    Node* temp_node = NULL;

    if (stack->top == NULL) return;
    else {
        do {
            temp_node = stack->top;
            stack->top = stack->top->next;
            deleteNode(temp_node);
        } while (stack->top != NULL);
    }

}

void printStack(Stack* stack) {
    Node* temp_node = stack->top;

    do {
        printf("%d\n", temp_node->value);
        printf("-------\n");
        temp_node = temp_node->next;

    } while (temp_node != NULL);
}

int main() {
    Stack* stack = NULL;
    int input = 0;

    printf("\n");

    while (1) {
        printf("1. CREATE STACK\n");
        printf("2. PUSH TO STACK\n");
        printf("3. POP FROM STACK\n");
        printf("4. PEEK\n");
        printf("5. SHOW ALL STACK\n");
        printf("6. DELETE STACK\n");
        printf("7. QUIT\n\n>> ");

        scanf_s("%d", &input);

        system("cls");

        switch (input) {
        case 1:
            if (stack == NULL) {
                stack = newStack();
                printf("CREATE SUCCESSFUL\n\n");
            }
            else {
                printf("STACK IS ALREADY EXIST\n\n");
            }

            break;
        case 2:
            if (stack != NULL) {
                printf("INSERT >> ");
                scanf_s("%d", &input);

                push(stack, input);
                printf("INSERT VALUE SUCCESSFUL\n\n");
            }
            else {
                printf("THERE IS NO STACK\n\n");
            }

            break;
        case 3:
            if (stack != NULL) {
                printf("POP\n");
                printf(">> [ %d ]\n\n", pop(stack));
            }
            else {
                printf("THERE IS NO STACK\n\n");
            }

            break;
        case 4:
            if (stack != NULL) {
                printf("PEEK\n");
                printf("VALUE : [ %d ]\n\n", peek(stack));
            }
            else {
                printf("THERE IS NO STACK\n\n");
            }

            break;
        case 5:
            if (stack != NULL) printStack(stack);
            else printf("THERE IS NO STACK\n\n");

            break;
        case 6:
            if (stack != NULL) {
                printf("DELETE SUCCESSFUL\n\n");
                deleteStack(stack);
            }
            else {
                printf("THERE IS NO STACK\n\n");
            }
            
            break;
        case 7:
            if (stack != NULL) deleteStack(stack);
            return;
        default:
            printf("WRONG INPUT\n\n");
            break;
        }
    }

    return 0;
}
