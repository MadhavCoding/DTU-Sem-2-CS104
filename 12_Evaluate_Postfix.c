#include <stdio.h>
#define MAXNUM 20

struct Stack
{
    int top;
    float arr[MAXNUM];
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

void Push (struct Stack* s, float x)
{
    if(isFull(*s)) 
    {
        return;
    }
    s->top = s->top + 1;
    s->arr[s->top] = x;
}

float Pop (struct Stack* s)
{
    if(isEmpty(*s))
    {
        return -1;
    }
    float x = s->arr[s->top];
    s->top = s->top - 1;
    return x;
}

float value_of (char c)
{
    switch (c)
    {
    case 'a':
        return 6.2;
        break;
    case 'b':
        return 5.0;
        break;
    case 'c':
        return 3.4;
        break;
    case 'd':
        return 2.1;
        break;

    default:
        break;
    }
}

float compute (float op1, float op2, char operator)
{
    switch (operator)
    {
    case '+':
        return (op1 + op2);
        break;
    case '-':
        return (op1 - op2);
        break;
    case '*':
        return (op1 * op2);
        break;
    case '/':
        return (op1 / op2);
        break;
    
    default:
        break;
    }
}

int isOperand (char c)
{
    if(c >= 'a' && c <= 'd') return 1;
    return 0;
}

int isOperator (char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/') return 1;
    return 0;
}

float Evaluate (char postfix[])
{
    struct Stack s;
    initialise(&s);
    int i = 0;
    while (postfix[i] != '\0')
    {
        if (isOperand(postfix[i]))
        {
            Push(&s, value_of(postfix[i]));
        }
        else if (isOperator(postfix[i]))
        {
            float op2 = Pop(&s);
            float op1 = Pop(&s);
            if(op2 == -1 || op1 == -1)
            {
                printf("Incorrect Postfix Expression\n");
                return -1;
            }
            float result = compute(op1, op2, postfix[i]);
            Push(&s, result);
        }
        else
        {
            printf("Incorrect Postfix Expression\n");
            return -1;
        }
        i++;
    }
    float result = Pop(&s);
    if(! isEmpty(s) || result == -1)
    {
        printf("Incorrect Postfix Expression\n");
        return -1;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    char postfix[MAXNUM];
    scanf("%s", &postfix);
    float answer = Evaluate(postfix);
    if(answer != -1) printf("The answer is %f\n", answer);
    return 0;
}