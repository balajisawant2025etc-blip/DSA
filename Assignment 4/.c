#include <stdio.h>

struct Student
{
    int roll;
    char name[30];
    float marks;
};

int main()
{
    struct Student s[100];
    int n, i, ch, roll, found;
    float marks;
    struct Student temp;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d", i + 1);

        printf("\nEnter roll number: ");
        scanf("%d", &s[i].roll);

        printf("Enter name: ");
        scanf("%s", s[i].name);

        printf("Enter marks: ");
        scanf("%f", &s[i].marks);
    }

    do
    {
        printf("\n\n1) Display");
        printf("\n2) Search");
        printf("\n3) Modify");
        printf("\n4) Sort by marks");
        printf("\n5) Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\nStudent Details:\n");

                for(i = 0; i < n; i++)
                {
                    printf("\nRoll Number: %d", s[i].roll);
                    printf("\nName: %s", s[i].name);
                    printf("\nMarks: %.2f\n", s[i].marks);
                }
                break;

            case 2:
                printf("\nEnter roll number to search: ");
                scanf("%d", &roll);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(s[i].roll == roll)
                    {
                        printf("\nStudent found");
                        printf("\nRoll Number: %d", s[i].roll);
                        printf("\nName: %s", s[i].name);
                        printf("\nMarks: %.2f", s[i].marks);

                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    printf("\nStudent not found");

                break;

            case 3:
                printf("\nEnter roll number to modify: ");
                scanf("%d", &roll);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(s[i].roll == roll)
                    {
                        printf("Enter new name: ");
                        scanf("%s", s[i].name);

                        printf("Enter new marks: ");
                        scanf("%f", &s[i].marks);

                        found = 1;
                        printf("Record modified successfully");
                        break;
                    }
                }

                if(found == 0)
                    printf("Student not found");

                break;

            case 4:
                for(i = 0; i < n - 1; i++)
                {
                    for(int j = 0; j < n - i - 1; j++)
                    {
                        if(s[j].marks > s[j + 1].marks)
                        {
                            temp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = temp;
                        }
                    }
                }

                printf("\nRecords sorted by marks");
                break;

            case 5:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid choice");
        }

    } while(ch != 5);

    return 0;
}
