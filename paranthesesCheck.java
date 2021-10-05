#include <stdio.h>
#include <stdlib.h>

struct stack
{
    char data;
    struct stack *next;
};
int isEmpty(struct stack *top)
{
    struct stack *current = top;
    if (current == NULL)
        return 1;
    else
        return 0;
}
int isFull(struct stack *top)
{
    struct stack *current = (struct stack *)malloc(sizeof(struct stack));
    if (current == NULL)
        return 1;
    else
        return 0;
}
void push(struct stack **top, char data)
{
    if (isFull(*top) != 1)
    {
        struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
        struct stack *current;
        current = (*top);
        ptr->data = data;
        ptr->next = current;
        (*top) = ptr;
    }
    else
        printf("Stack OverFlow\n");
}
int peek(struct stack *top, int pos)
{
    struct stack *current = top;
    while (current->next != NULL && pos > 1)
    {
        current = current->next;
        pos--;
    }
    return current->data;
}
void print(struct stack *top)
{
    struct stack *current = top;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void pop(struct stack **top)
{
    if (isEmpty(*top) != 1)
    {
        struct stack *current = (*top);
        (*top) = (*top)->next;
        free(current);
    }
    else
        printf("Stack underflow\n");
}
int ParenthesesCheck(char * s){
    struct stack * local_stack=NULL;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '['){
            push(&local_stack, s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            char ascii;
            if(s[i]==')')
                ascii = '(';
            else if(s[i] == '}')
                ascii = '{';
            else 
                ascii = '[';

            if (isEmpty(local_stack) == 1)
            {
                free(local_stack);
                return 0;
            }
            else if(ascii==local_stack->data){
                pop(&local_stack);
            }
            else {
                free(local_stack);
                return 0;
            }
            
        }
    }
    if (isEmpty(local_stack) != 1 ){
        free(local_stack);
        return 0;
    }
    else{
        free(local_stack);
        return 1;
    }

}

int main()
{
    struct stack *top = NULL;
    char str[56];
    int flag = 0;
    scanf("%[^\n]%*c", str);
    if(!ParenthesesCheck(str))
        printf("Invalid Parentheses Order !!\n");
    else printf("Valid PArentheses !!\n");
    return 0;
}
