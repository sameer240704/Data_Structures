#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

void push(char );
char pop();
int is_Matching(char , char );
int is_Balanced(char *);

char stack[MAX];
int tos = -1;

int main() {
    char name[MAX];
    printf("Enter the expression : ");
    scanf("%99s", name); //Will take all the characters in the string and prevents buffer overflow
    if(is_Balanced(name))
        printf("\nExpression is Balanced");
    else  
        printf("\nExpression is Not Balanced");
    return 0;
}

void push(char ch) { //Normal Push
    if(tos == (MAX-1))
        printf("\nStack is Full!");
    else    
        stack[++tos] = ch;
}

char pop() { //Normal Pop
    if(tos == -1)
        printf("\nStack is Empty!");
    else
        return stack[tos--];
}

int is_Matching(char ch1, char ch2) {
    if(ch1 == '(' && ch2 == ')') //True
        return 1; 
    if(ch1 == '{' && ch2 == '}') //True
        return 1;
    if(ch1 == '[' && ch2 == ']') //True
        return 1;
    else //False
        return 0;
}

int is_Balanced(char *ptr) { //General way of passing a string(character array) to a function
    int i;
    for(i=0 ; i<strlen(ptr) ; i++) {
        if(ptr[i] != ' ') {
            if(ptr[i] == '(' || ptr[i] == '{' || ptr[i] == '[') //If open brackets then push
                push(ptr[i]);
            else if(ptr[i] == ')' || ptr[i] == '}' || ptr[i] == ']') { //If closing brackets
                if(tos == -1) //No opening bracket for current closing bracket so NOT BALANCED
                    return 0;
                else if(!is_Matching(pop(), ptr[i])) //Checks if the current bracket does not matches with the top of the stack element(by pop())
                    return 0;
            }   
        }
        else 
            continue;
    }
    if(tos == -1)
        return 1; //Balanced
    else 
        return 0; //Not Balanced
}