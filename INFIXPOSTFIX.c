#include<stdio.h>
#include<conio.h>
void push(char ch);
char pop();
int priority(char ch);
char stack[100];
int top = -1;

int main() {
    char exp[100], *e, ch;
    clrscr();
    printf("\nEnter the expression : ");
    scanf("%s", exp);
    e = exp;
    while(*e != '\0') {
        if(isalnum(*e))
            printf("%c ", *e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')') {
            while((ch = pop()) != '(')
                printf("%c ", ch);
        }
        else if(*e == ' ')
            e++;
        else {
            while(priority(stack[top]) >= priority(*e)) 
                printf("%c ", pop());
            push(*e);
        }
        e++;
    }
    while(top != -1)
        printf("%c ", pop());
    getch();
    return 0;
}


void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    if(top == -1)
        return -1;
    else    
        return stack[top--];
}

int priority(char ch) {
    if(ch == '(')
        return 0;
    else if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    return 0;
}