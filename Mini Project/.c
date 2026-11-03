
#include <stdio.h>
#include <string.h>

#define MAX 8

struct Team {
    char name[30];
};

int main() {
    struct Team teams[MAX];
    char temp[30];
    int n, i, round = 1, match = 1, winner;

    printf("Enter number of teams (2, 4 or 8): ");
    scanf("%d", &n);

    if (n != 2 && n != 4 && n != 8) {
        printf("Enter only 2, 4 or 8 teams!\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Enter team %d name: ", i + 1);
        scanf("%29s", teams[i].name);
    }

    while (n > 1) {
        printf("\n--- Round %d ---\n", round);

        for (i = 0; i < n; i += 2) {
            printf("\nMatch %d: %s vs %s\n",
                   match++, teams[i].name, teams[i + 1].name);

            printf("Enter winner (1 or 2): ");
            scanf("%d", &winner);

            if (winner != 1 && winner != 2) {
                printf("Invalid choice! Try again.\n");
                i -= 2;
                match--;
                continue;
            }

            if (winner == 2) {
                strcpy(temp, teams[i + 1].name);
                strcpy(teams[i + 1].name, teams[i].name);
                strcpy(teams[i].name, temp);
            }

            strcpy(teams[i / 2].name, teams[i].name);
        }

        n /= 2;
        round++;
    }

    printf("\n🏆 Tournament Champion: %s\n", teams[0].name);

    return 0;
}
