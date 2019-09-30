#include <bits/stdc++.h>
using namespace std;

int random_state [3][3] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
int goal_state [3][3] = {3, 6, 1, 2, 0, 8, 7, 4, 5};
bool numbers_flag [9] = {false, false, false, false, false, false, false, false, false};
int temp;
int row_location[9], column_location[9];
int cnt = 0;
int A, AA, B, BB, C, CC, D, DD;

int misplaced_tiles(int a, int b, int aa, int bb)
{
    swap(random_state[a][b], random_state[aa][bb]);
    int x = 0;

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (goal_state[i][j] != random_state[i][j])
            {
                x++;
            }
        }
    }

    swap(random_state[a][b], random_state[aa][bb]);
    return x;
}

void swap_tiles (int a, int b, int aa, int bb)
{
    swap(random_state[a][b], random_state[aa][bb]);
    swap(row_location[random_state[a][b]], row_location[random_state[aa][bb]]);
    swap(column_location[random_state[a][b]], column_location[random_state[aa][bb]]);
    return;
}

void solve_puzzle ()
{
    printf("Step : %d\n", cnt++);
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            printf("%d ", random_state[i][j]);
        }
        printf("\n");
    }

    if (random_state[0][0] == goal_state[0][0] && random_state[0][1] == goal_state[0][1] && random_state[0][2] == goal_state[0][2] && random_state[1][0] == goal_state[1][0] && random_state[1][1] == goal_state[1][1] && random_state[1][2] == goal_state[1][2] && random_state[2][0] == goal_state[2][0] && random_state[2][1] == goal_state[2][1] && random_state[2][2] == goal_state[2][2])
    {
        printf("\nPuzzle Solved !!!\n");
        return;
    }


    if (row_location[0] == 0 && column_location[0] == 0)
    {
        A = misplaced_tiles (0, 0, 0, 1);
        B = misplaced_tiles (0, 0, 1, 0);
        if (A < B)
        {
            swap_tiles(0, 0, 0, 1);
        }
        else if (B < A)
        {
            swap_tiles(0, 0, 1, 0);
        }
        else
        {
            srand(time(0));
            temp = rand() % 2;
            if (temp == 0)
            {
                swap_tiles(0, 0, 0, 1);
            }
            else
            {
                swap_tiles(0, 0, 1, 0);
            }
        }
    }
    else if (row_location[0] == 0 && column_location[0] == 2)
    {
        A = misplaced_tiles (0, 2, 0, 1);
        B = misplaced_tiles (0, 2, 1, 2);
        if (A < B)
        {
            swap_tiles(0, 2, 0, 1);
        }
        else if (B < A)
        {
            swap_tiles(0, 2, 1, 2);
        }
        else
        {
            srand(time(0));
            temp = rand() % 2;
            if (temp == 0)
            {
                swap_tiles(0, 2, 0, 1);
            }
            else
            {
                swap_tiles(0, 2, 1, 2);
            }
        }
    }
    else if (row_location[0] == 2 && column_location[0] == 0)
    {
        A = misplaced_tiles (2, 0, 1, 0);
        B = misplaced_tiles (2, 0, 2, 1);
        if (A < B)
        {
            swap_tiles(2, 0, 1, 0);
        }
        else if (B < A)
        {
            swap_tiles(2, 0, 2, 1);
        }
        else
        {
            srand(time(0));
            temp = rand() % 2;
            if (temp == 0)
            {
                swap_tiles(2, 0, 1, 0);
            }
            else
            {
                swap_tiles(2, 0, 2, 1);
            }
        }
    }
    else if (row_location[0] == 2 && column_location[0] == 2)
    {
        A = misplaced_tiles (2, 2, 2, 1);
        B = misplaced_tiles (2, 2, 1, 2);
        if (A < B)
        {
            swap_tiles(2, 2, 2, 1);
        }
        else if (B < A)
        {
            swap_tiles(2, 2, 1, 2);
        }
        else
        {
            srand(time(0));
            temp = rand() % 2;
            if (temp == 0)
            {
                swap_tiles(2, 2, 2, 1);
            }
            else
            {
                swap_tiles(2, 2, 1, 2);
            }
        }
    }
    else if (row_location[0] == 0 && column_location[0] == 1)
    {
        A = misplaced_tiles (0, 1, 0, 0);
        B = misplaced_tiles (0, 1, 0, 2);
        C = misplaced_tiles (0, 1, 1, 1);

        if (A < B && A < C)
        {
            swap_tiles(0, 1, 0, 0);
        }
        else if (B < A && B < C)
        {
            swap_tiles(0, 1, 0, 2);
        }
        else if (C < A && C < B)
        {
            swap_tiles(0, 1, 1, 1);
        }
        else
        {
            srand(time(0));
            temp = rand() % 3;
            if (temp == 0)
            {
                swap_tiles(0, 1, 0, 0);
            }
            else if (temp == 1)
            {
                swap_tiles(0, 1, 0, 2);
            }
            else
            {
                swap_tiles(0, 1, 1, 1);
            }
        }
    }
    else if (row_location[0] == 1 && column_location[0] == 0)
    {
        A = misplaced_tiles (1, 0, 0, 0);
        B = misplaced_tiles (1, 0, 2, 0);
        C = misplaced_tiles (1, 0, 1, 1);

        if (A < B && A < C)
        {
            swap_tiles(1, 0, 0, 0);
        }
        else if (B < A && B < C)
        {
            swap_tiles(1, 0, 2, 0);
        }
        else if (C < A && C < B)
        {
            swap_tiles(1, 0, 1, 1);
        }
        else
        {
            srand(time(0));
            temp = rand() % 3;
            if (temp == 0)
            {
                swap_tiles(1, 0, 0, 0);
            }
            else if (temp == 1)
            {
                swap_tiles(1, 0, 2, 0);
            }
            else
            {
                swap_tiles(1, 0, 1, 1);
            }
        }
    }
    else if (row_location[0] == 1 && column_location[0] == 2)
    {
        A = misplaced_tiles (1, 2, 0, 2);
        B = misplaced_tiles (1, 2, 2, 2);
        C = misplaced_tiles (1, 2, 1, 1);

        if (A < B && A < C)
        {
            swap_tiles(1, 2, 0, 2);
        }
        else if (B < A && B < C)
        {
            swap_tiles(1, 2, 2, 2);
        }
        else if (C < A && C < B)
        {
            swap_tiles(1, 2, 1, 1);
        }
        else
        {
            srand(time(0));
            temp = rand() % 3;
            if (temp == 0)
            {
                swap_tiles(1, 2, 0, 2);
            }
            else if (temp == 1)
            {
                swap_tiles(1, 2, 2, 2);
            }
            else
            {
                swap_tiles(1, 2, 1, 1);
            }
        }
    }
    else if (row_location[0] == 2 && column_location[0] == 1)
    {
        A = misplaced_tiles (2, 1, 2, 0);
        B = misplaced_tiles (2, 1, 2, 2);
        C = misplaced_tiles (2, 1, 1, 1);

        if (A < B && A < C)
        {
            swap_tiles(2, 1, 2, 0);
        }
        else if (B < A && B < C)
        {
            swap_tiles(2, 1, 2, 2);
        }
        else if (C < A && C < B)
        {
            swap_tiles(2, 1, 1, 1);
        }
        else
        {
            srand(time(0));
            temp = rand() % 3;
            if (temp == 0)
            {
                swap_tiles(2, 1, 2, 0);
            }
            else if (temp == 1)
            {
                swap_tiles(2, 1, 2, 2);
            }
            else
            {
                swap_tiles(2, 1, 1, 1);
            }
        }
    }
    else if (row_location[0] == 1 && column_location[0] == 1)
    {
        A = misplaced_tiles (1, 1, 0, 1);
        B = misplaced_tiles (1, 1, 1, 0);
        C = misplaced_tiles (1, 1, 1, 2);
        D = misplaced_tiles (1, 1, 2, 1);

        if (A < B && A < C && A < D)
        {
            swap_tiles(1, 1, 0, 1);
        }
        else if (B < A && B < C && B < D)
        {
            swap_tiles(1, 1, 1, 0);
        }
        else if (C < A && C < B && C < D)
        {
            swap_tiles(1, 1, 1, 2);
        }
        else if (D < A && D < B && D < C)
        {
            swap_tiles(1, 1, 2, 1);
        }
        else
        {
            srand(time(0));
            temp = rand() % 4;
            if (temp == 0)
            {
                swap_tiles(1, 1, 0, 1);
            }
            else if (temp == 1)
            {
                swap_tiles(1, 1, 1, 0);
            }
            else if (temp == 2)
            {
                swap_tiles(1, 1, 1, 2);
            }
            else
            {
                swap_tiles(1, 1, 2, 1);
            }
        }
    }

    solve_puzzle();
}

int main()
{
    printf("Generating Random State...\n\n");
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            while(random_state[i][j] == -1)
            {
                srand(time(0));
                temp = rand() % 9;
                if (numbers_flag[temp] == false)
                {
                    numbers_flag[temp] = true;
                    random_state[i][j] = temp;
                    row_location[temp] = i;
                    column_location[temp] = j;
                    break;
                }
            }
        }
    }
    printf("Random State : \n\n");
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            printf("%d ", random_state[i][j]);
        }
        printf("\n");
    }

    solve_puzzle();

    return 0;
}
