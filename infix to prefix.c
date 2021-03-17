#include<conio.h>
#include<stdio.h>
#include<string.h>
char infix[100];
char postfix[100];
char prefix[100];
char stack[100];
char reverse[100];
int top=-1;
int pop()
{
    return stack[top--];
}
int push(int val)
{
    top++;
    stack[top]=val;
}
char revers_exp(char arr[],char array[])
{
    int j=0;
    for(int i=strlen(arr)-1;i>=0;i--)
    {
        if(arr[i]== ')')
            array[j]='(';
        else if(arr[i]=='(')
            array[j]=')';
        else
            array[j]=arr[i];
        j++;
    }
    array[j]='\0';
    puts(array);
}
int is_operator(char x)
{
    if(x=='+'||x=='^'||x=='/'||x=='*'||x=='-')
        return 1;
    else
        return 0;
}
int priority(char x)
{
    if(x=='^')
        return 3;
    else if(x=='*'||x=='/')
        return 2;
    else if(x=='+'||x=='-')
        return 1;
    else
        return 0;
}
void infixtopostfix(char infix[])
{
    int i=0,j=0;
    char temp;
    while(infix[i]!=0)
    {
        if(infix[i]=='(')
            push(infix[i]);
        else if(is_operator(infix[i])==1)
        {
            temp=pop();
            while(priority(temp)>priority(infix[i]))
            {
               postfix[j]=temp;
               temp = pop();
               j++;
            }
            push(temp);
            push(infix[i]);
        }
        else if(infix[i]==')')
        {
            temp = pop();
            while(temp!='(')
            {
                postfix[j]=temp;
                temp=pop();
                j++;
            }
        }
        else
        {
            postfix[j]=infix[i];
            j++;
        }
           i++;
    }
    while(infix[i]=='\0')
    {
        postfix[j]=infix[i];
        j++;
        i++;
    }
    postfix[i]='\0';
    puts(postfix);
}
infixtoprefix(char infix[])
{
    printf("\nReverse infix expression : ");
    revers_exp(infix,reverse);
    printf("\n--------------------------------------------------\n");
    printf("\nReverse Infix expression to postfix conversion  : ");
    infixtopostfix(reverse);
    printf("\n--------------------------------------------------\n");
    printf("\nReverse postfix expression || Prefix expression  : ");
    revers_exp(postfix,prefix);
}

main()
{
    printf("\nEnter the infix  expression ");
    gets(infix);
    printf("\n--------------------------------------------------\n");
    infixtoprefix(infix);
}
