#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(void)
{
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the value to be pushed into the Stack: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = top;
    top = newnode;

    printf("Value pushed successfully\n");
}

void pop(void)
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        temp = top;

        printf("The value popped: %d\n", top->data);

        top = top->next;

        free(temp);
    }
}

void peek(void)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("The top value of the Stack is: %d\n", top->data);
    }
}

void display(void)
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        temp = top;

        printf("Stack elements are:\n");

        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main(void)
{
    int choice;

    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                while (top != NULL)
                {
                    struct node *temp = top;
                    top = top->next;
                    free(temp);
                }

                return 0;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
