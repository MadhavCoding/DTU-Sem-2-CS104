#include <stdio.h>
#define MAXNUM 20

struct Stack
{
    int top;
    char arr[MAXNUM];
};

void initialise (struct Stack * s)
{
    s->top = -1;
}

int isFull (struct Stack s)
{
    if (s.top == MAXNUM-1) return 1;
    return 0;
}

int isEmpty (struct Stack s)
{
    if (s.top == -1) return 1;
    return 0;
}

void Push (struct Stack* s, char x)
{
    if(isFull(*s)) 
    {
        return;
    }
    s->top = s->top + 1;
    s->arr[s->top] = x;
}

char Pop (struct Stack* s)
{
    if(isEmpty(*s))
    {
        return -1;
    }
    char x = s->arr[s->top];
    s->top = s->top - 1;
    return x;
}

int ISP (char c)
{
    switch (c)
    {
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '(':
        return 0;
        break;
    case '#':
        return -1;
        break;
    
    default:
        break;
    }
}

int ICP (char c)
{
    switch (c)
    {
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '(':
        return 4;
        break;
    
    default:
        break;
    }
}

int isOperand (char c)
{
    if(c >= 'a' && c <= 'z') return 1;
    return 0;
}

int isOperator (char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/') return 1;
    return 0;
}

void Infix_to_Postfix (char infix[], char postfix[])
{
    struct Stack s;
    int i = 0; int j = 0;
    initialise(&s);
    Push(&s, '#');
    while (infix[i] != '#')
    {
        if(isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else if(isOperator(infix[i]))
        {
            if(ISP(s.arr[s.top]) < ICP(infix[i]))
            {
                Push(&s, infix[i]);
                i++;
            }
            else
            {
                while (ISP(s.arr[s.top]) >= ICP(infix[i]))
                {
                    postfix[j++] = Pop(&s);
                }
                Push(&s, infix[i]);
                i++;
            }
        }
        else if(infix[i] == '(')
        {
            Push(&s, '(');
            i++;
        }
        else if(infix[i] == ')')
        {
            char x;
            do
            {
                x = Pop(&s);
                if(x != '(') postfix[j++] = x;
            } while (x != '(');
            i++;
        }
    }
    
    while (s.top >= 0)
    {
        postfix[j++] = Pop(&s);
    }
    postfix[j] = '\0';
}

int main(int argc, char const *argv[])
{
    char infix[MAXNUM];
    printf("Enter Infix Expression : ");
    scanf("%s", infix);
    char postfix[MAXNUM];
    Infix_to_Postfix(infix, postfix);
    printf("Infix : %s\nPostfix : %s\n", infix, postfix);
    return 0;
}