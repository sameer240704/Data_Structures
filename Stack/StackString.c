#include<stdio.h>
#include<conio.h>
void push(char ch);
char pop();
int tos = -1;
char name[100];

int main() {
    char *ptr, ch;
    printf("\nEnter your name : ");
    scanf("%s", name);
    ptr = name;
    while(*ptr != '\0') {
        push(*ptr);
        ptr++;
    }
    printf("\nReversed String is : ");
    while(tos >= 0) {
        printf("%c", pop());
    }
    return 0;
}

void push(char ch) {
    if(tos == 99)
        printf("\nName is too long!");
    else 
        name[++tos] = ch;
}

char pop() {
    // if(tos == -1) {
    //     printf("\n\nName Ends!");
    //     return '\0';
    // }
    // else 
        return name[tos--];
}