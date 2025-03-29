#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct stack{
    char arr[MAX_SIZE];
    int top;
};

void initialize(struct stack *s){
    s->top = -1;
}

bool isEmpty(struct stack *s){
    return s->top == -1;
}

void push(struct stack *s, char c){
    s->arr[++s->top] = c;
}

char pop(struct stack *s){
    return s->arr[s->top--];
}

bool check_parentheses(const char *exp)
{
    struct stack s;
    initialize(&s);
    while (*exp)
    {
        char c = *exp++;
        if (c == '(' || c == '[' || c == '{')
        {
            push(&s, c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (isEmpty(&s))
                return false;
            char topc = pop(&s);
            if ((c == ')' && topc != '(') || (c == ']' && topc != '[') || (c == '}' && topc != '{'))
                return false;
        }
    }
    return isEmpty(&s);
}

int main()
{
    const char *exp = "{[(])]}";
    if (check_parentheses(exp))
        printf("Valid parentheses\n");
    else
        printf("Invalid parentheses\n");
    return 0;
}
