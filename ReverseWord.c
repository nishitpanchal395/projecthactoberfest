#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
    char data;
    struct stack * next;
};
int isEmpty(struct stack **top){
    return (*top)==NULL;
}
void push(struct stack **top, char data){
    struct stack * ptr =(struct stack *)malloc(sizeof(struct stack));
    ptr->data= data;
    // printf("%c pushed in.\n",ptr->data);
    ptr->next =(*top);
    (*top)= ptr;
}
void pop(struct stack **top){
    struct stack * item = (*top);
    if(isEmpty<=0)
        printf("UnderFLow");
    else{
        (*top)=(*top)->next;
    printf("%c",item->data);
    free(item);
    } 
}

void printStack(struct stack * top){
    struct stack * ptr=(top);
    if(isEmpty!=0){
        printf("Empty stack.\n");
        return;
    }
    else {
        while(ptr!=NULL){
            printf("%c",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    int i;
    struct stack * top=NULL;
    char str[52];
    scanf("%[^\n]%*c",&str);
    for ( i =0;i<=strlen(str);i++){
        if((str[i]!=' ')&&(str[i]!='\0')){
            push(&top,str[i]);
        }
        else{
            while(top!=NULL){
                pop(&top);
            }
            if(i==0&&str[i]==' ')
                continue;
            else 
            printf(" ");
        }   
    }
    return 0;
}