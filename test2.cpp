#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cpush = 0, cpop = 0;
struct Node *f = NULL;
struct Node *r = NULL;
struct Node {
    int data;
    struct Node *next;
};
int empty(struct Node** top) {
    if (*top == NULL) {
        return 1;
    }
    return 0;
}
void push(struct Node** top, int x) {
    cpush++;
    struct Node* n = (struct Node*) malloc(sizeof(struct Node));
    n->data = x;
    n->next = *top;
    *top = n;

}
void pop(struct Node** top) {
    if (empty(top)) {
        printf("stack underflow\n");
        return ;
    }
    cpop++;
    struct Node* n = *top;
    *top = (*top)->next;
    free(n);

}
int stacktop(struct Node** top) {
    if (!empty(top)) {
        return (*top)->data;
    }
    return -1;
}
void Enqueue(struct Node** stk1, struct Node** stk2, int val) {
    while (!empty(stk1)) {
        push(stk2, stacktop(stk1));
        pop(stk1);
    }
    push(stk1, val);
    while (!empty(stk2)) {
        push(stk1, stacktop(stk2));
        pop(stk2);
    }
}
void Dequeue(struct Node** stk1, struct Node** stk2) {
    int x1 = -1;
    if (empty(stk1)) {
        printf("stack empty\n");
    }
    stacktop(stk1);
    pop(stk1);
}

int main() {



    struct Node* stk1 = NULL;
    struct Node* stk2 = NULL;

    int n, i = 0;
    char arr[100];
    scanf("%d", &n);
    for (i; i < n; i++) {
        scanf("%s", arr);
        if (arr[0] == 'D') {
            Dequeue(&stk1, &stk2);
        }
        else {
            int l = strlen(arr);
            if (arr[1] == '-') {
                int num = 0;
                for (int j = 2; j < l; j++) {
                    num = 10 * num + arr[j] - '0';
                }
                Enqueue(&stk1, &stk2, (-1)*num);
            }
            else {
                int num = 0;
                for (int j = 1; j < l; j++) {
                    num = 10 * num + arr[j] - '0';
                }
                Enqueue(&stk1, &stk2, num);
            }
        }
    }
    printf("%d\n", cpush);
    printf("%d", cpop);
    return 0;
}

