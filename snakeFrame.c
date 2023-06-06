#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 20

int score;
int gameOver;
int tailX[100], tailY[100];
int tailLength;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum Direction dir;

struct Location {
    int x;
    int y;
};
struct Location playerLoc, fruitLoc;

void Setup()
{
    playerLoc.x = WIDTH / 2;
    playerLoc.y = HEIGHT / 2;
    gameOver = false;
    dir = STOP;
    fruitLoc.x = rand() % WIDTH;
    fruitLoc.y = rand() % HEIGHT;
    score = 0;
}

void Draw()
{
    system("clear");
    int i, j;
    for (i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (j == 0 || j == WIDTH-1)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }

    for (i = 0; i < WIDTH +2; i++)
        printf("#");

}

void Input()
{
    // Code for handling user input
    // ...
}

void Logic()
{
    // Code for game logic
    // ...
}

int main()
{
    srand(time(NULL));
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        sleep(50);  // Adjust the speed of the game for macOS using usleep
    }
    return 0;
}
