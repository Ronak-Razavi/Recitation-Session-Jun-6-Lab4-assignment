#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 20

int score;
int gameOver;



struct Location {
    int x;
    int y;
};
struct Location playerLoc, fruitLoc;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum Direction dir;

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
    system("cls");
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
            else if (j == playerLoc.x && i == playerLoc.y)
                printf("O");
            else if (j == fruitLoc.x && i == fruitLoc.y)
                printf("X");
            else
                printf(" ");
        }
        printf("\n");


    }

    for (i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");
  
}

void Input()
{
    if (kbhit()){
        switch (getch())
        {
          case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
        }
    }
}

void Logic()
{
    switch (dir)
    {
    case LEFT:
        playerLoc.x=playerLoc.x-1;
        break;
    case RIGHT:
        playerLoc.x=playerLoc.x+1;
        break;
    case UP:
        playerLoc.y=playerLoc.y-1;
        break;
    case DOWN:
        playerLoc.y=playerLoc.y+1;
        break;

    }
    if (playerLoc.x>WIDTH)
    playerLoc.x=1;
    else if (playerLoc.x <= 0)
        playerLoc.x=WIDTH-1;
   if (playerLoc.x== fruitLoc.x && playerLoc.y == fruitLoc.y){
    score+=10;
    fruitLoc.x = rand() % WIDTH;
    fruitLoc.y = rand() % HEIGHT;

   }

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
        Sleep(10 );  // Adjust the speed of the game
    }
    return 0;
}
