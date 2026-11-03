#include <stdio.h>

#define V 5

int main()
{
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int visited[V] = {0};
    int edges = 0, min, u, v, total = 0;

    visited[0] = 1;

    printf("Edge   Weight\n");

    while (edges < V - 1)
    {
        min = 999;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 1)
            {
                for (int j = 0; j < V; j++)
                {
                    if (visited[j] == 0 &&
                        graph[i][j] != 0 &&
                        graph[i][j] < min)
                    {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d    %d\n", u, v, min);

        visited[v] = 1;
        total += min;
        edges++;
    }

    printf("Total MST Weight = %d\n", total);

    return 0;
}
