#include<stdio.h>
#include<string.h>

void reverse(char input[]);
int palindrome(char input[]);
void copy(char input[], char output[]);
void substring(char input[]);
int stringlength(char input[]);
void compare(char input[], char output[]);

int main()
{
    char str[10], output[10];
    int ch, c;

    printf("\nEnter the string : ");
    scanf("%s", str);

    do
    {
        printf("\n1) Copy");
        printf("\n2) Palindrome");
        printf("\n3) Reverse");
        printf("\n4) Substring");
        printf("\n5) Compare");
        printf("\n6) Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                copy(str, output);
                break;

            case 2:
                c = palindrome(str);

                if(c == 1)
                    printf("The given string is a Palindrome");
                else
                    printf("The given string is not a palindrome");
                break;

            case 3:
                reverse(str);
                break;

            case 4:
                substring(str);
                break;

            case 5:
                compare(str, output);
                break;

            case 6:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice");
        }

    }while(ch != 6);

    return 0;
}

int palindrome(char name[])
{
    int i = 0, j = 0;

    while(name[j] != '\0')
        j++;

    j--;

    while(i < j)
    {
        if(name[i] != name[j])
            return 0;

        i++;
        j--;
    }

    return 1;
}

void copy(char input[], char output[])
{
    int i;

    for(i = 0; input[i] != '\0'; i++)
        output[i] = input[i];

    output[i] = '\0';

    printf("\nThe output (copied) string is: ");
    printf("%s", output);
}

void substring(char input[])
{
    int i, n, position;
    char output[10];

    printf("Enter the position of substring: ");
    scanf("%d", &position);

    n = stringlength(input);

    if(position < n)
    {
        for(i = 0; i < n - position; i++)
            output[i] = input[position + i];

        output[i] = '\0';

        printf("\nInput string: %s", input);
        printf("\nOutput substring: %s", output);
    }
    else
    {
        printf("\nPosition entered is out of range");
    }
}

int stringlength(char input[])
{
    int i = 0;

    while(input[i] != '\0')
        i++;

    return i;
}

void reverse(char input[])
{
    int n, i;
    char output[10];

    n = stringlength(input);

    for(i = 0; i < n; i++)
        output[n - 1 - i] = input[i];

    output[i] = '\0';

    printf("\nInput string: %s", input);
    printf("\nOutput (reversed) string: %s", output);
}

void compare(char input[], char output[])
{
    printf("\nEnter second string: ");
    scanf("%s", output);

    if(strcmp(input, output) == 0)
        printf("Strings are equal");
    else
        printf("Strings are not equal");
}
