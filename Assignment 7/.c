#include <stdio.h>
#include <ctype.h>

#define size 80

struct stack
{
    double s[size];
    int top;
} st;

void push(double x)
{
    if (st.top == size - 1)
    {
        printf("\nStack full");
        return;
    }

    st.top++;
    st.s[st.top] = x;
}

double pop(void)
{
    double x;

    if (st.top == -1)
    {
        printf("\nStack empty");
        return 0;
    }

    x = st.s[st.top];
    st.top--;

    return x;
}

double evaluate(char exp[])
{
    int i;
    double op1, op2, result;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit((unsigned char)exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch (exp[i])
            {
                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    if (op2 == 0)
                    {
                        printf("\nDivision by zero error");
                        return 0;
                    }

                    result = op1 / op2;
                    break;

                default:
                    printf("\nInvalid operator");
                    return 0;
            }

            push(result);
        }
    }

    return pop();
}

int main(void)
{
    char exp[size];
    double result;

    st.top = -1;

    printf("Enter postfix expression: ");
    scanf("%79s", exp);

    result = evaluate(exp);

    printf("\nResult = %f\n", result);

    return 0;
}
