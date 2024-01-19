// Evaluate Postfix Expressions using a Stack: Write a program in C programming language to evaluate a given postfix expression using a stack. Handle operators like &#39;+&#39;, &#39;- #39;, &#39;*&#39;, and &#39;/&#39; along with integer operands. Ensure that the program can handle expressions with multiple digits.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size_80;
    int top_80;
    float *arr_80;
};

int isEmpty(struct stack *s)
{
    if (s->top_80 == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *s)
{
    if (s->top_80 == s->size_80 - 1)
    {
        return 1;
    }
    return 0;
}

float push(struct stack *s, float val)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->arr_80[++(s->top_80)] = val;
    }
    return 0;
}

float pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow \n ");
    }
    else
    {
        return s->arr_80[(s->top_80)--];
    }
}

float charToint(char *exp_80)
{
    float val = 0;
    int len = strlen(exp_80);
    for (int i = 0; i < len; i++)
    {
        val *= 10;
        val += (int)(exp_80[i]) - (int)'0';
    }
    return val;
}

float calc(float oprnd1, float oprnd2, char op)
{
    switch (op)
    {
    case '+':
        return (oprnd1 + oprnd2);
    case '-':
        return (oprnd1 - oprnd2);
    case '/':
        return (oprnd1 / oprnd2);
    case '*':
        return (oprnd1 * oprnd2);
    }
}

float eval(char *exp_80)
{
    float evalAns_80 = 0;
    int len = strlen(exp_80);
    struct stack *s_80 = (struct stack *)malloc(sizeof(struct stack));
    s_80->size_80 = len;
    s_80->top_80 = -1;
    s_80->arr_80 = (float *)malloc(len * sizeof(float));
    char *numExp_80 = (char *)malloc(10);
    int numExpind_80 = 0;
    char *operators = "+-/*";
    char *numbers = "0123456789";
    for (int i = 0; exp_80[i] != '\0'; i++)
    {
        if (exp_80[i] == ' ' && strchr(operators, exp_80[i - 1]) == NULL)
        {
            float val = charToint(numExp_80);
            numExpind_80 = 0;
            push(s_80, val);
        }
        else if (strchr(operators, exp_80[i]) != NULL)
        {
            float num1 = pop(s_80);
            float num2 = pop(s_80);
            evalAns_80 = calc(num2, num1, exp_80[i]);
            push(s_80, evalAns_80);
        }
        else if (strchr(numbers, exp_80[i]) != NULL)
        {
            numExp_80[numExpind_80] = exp_80[i];
            numExpind_80++;
            numExp_80[numExpind_80] = '\0';
        }
    }
    evalAns_80 = pop(s_80);
    free(numExp_80);
    free(s_80->arr_80);
    free(s_80);
    return evalAns_80;
}

int main()
{
    char *exp_80 = "10 0 40 30 + + -";
    float ans_80 = eval(exp_80);
    printf("The answer is %.2f", ans_80);
    return 0;
}
