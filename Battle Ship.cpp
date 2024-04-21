#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>
using namespace std;

char Board[24][33];
int PlaneX[3] = {20, 21, 22};
int PlaneY[5] = {14, 15, 16, 17, 18};

void Game(int score, int health)
{
    cout << " SCORE: " << score << "\t\tHEALTH: " << health << '*' << endl;
    cout << "***********************************" << endl;
    for (int i = 0; i < 24; i++)
    {
        cout << '*';
        for (int j = 0; j < 33; j++)
            cout << Board[i][j];
        cout << '*' << endl;
    }
    cout << "***********************************" << endl;
    if (score < 30)
        cout << "\n\t     Stage : 1" << endl;
    else
        cout << "\n\t     Stage : 2" << endl;
}

void enemyFire(int PlaneX, int PlaneY)
{
    Board[PlaneX][PlaneY] = '!';
}

void updateEnemyFire(int score, int &health)
{
    for (int i = 23; i >= 0; i--)
    {
        for (int j = 33; j >= 0; j--)
        {
            if (Board[i - 1][j] == '!' && Board[i + 1][j] != '|')
            {
                if (Board[i][j] != '$')
                    Board[i][j] = '!';
                else
                    health--;
                if (score < 30)
                    Board[i - 1][j] = ' ';
                else if (Board[i - 2][j] != '#')
                    Board[i - 2][j] = ' ';
            }
            if (Board[i][j] == '!' && Board[i - 15][j] == '#')
                enemyFire(i - 14, j);
        }
    }
}

void updateplaneFire(int &score)
{
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 33; j++)
        {
            if (Board[i + 1][j] == '|')
            {
                if (Board[i][j] == '#')
                    score += 2;
                if (Board[i][j] == '+')
                    Board[i + 1][j] = '+';
                Board[i][j] = '|';
                Board[i + 3][j] = ' ';
                break;
            }
        }
    }
}

void updateGifts(int &score, int &health)
{
    int randomGift = 0;
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 33; j++)
        {
            if (Board[i][j] == '+')
            {
                if (Board[i + 1][j] == '$')
                {
                    randomGift = rand() % 4;

                    switch (randomGift)
                    {
                    case 0:
                        health++;
                        break;
                    case 1:
                        score += 10;
                        break;
                    case 2:
                        score += 20;
                        break;
                    case 3:
                        score += 15;
                        health += 2;
                        break;
                    }
                }
                Board[i + 1][j] = '+';
                Board[i][j] = ' ';
                i = 24;
                j = 33;
            }
        }
    }
}

void plane(int health)
{
    Board[PlaneX[0]][PlaneY[2]] = '$';
    Board[PlaneX[1]][PlaneY[1]] = '$';
    Board[PlaneX[1]][PlaneY[2]] = '_';
    Board[PlaneX[1]][PlaneY[3]] = '$';
    Board[PlaneX[2]][PlaneY[0]] = '$';
    Board[PlaneX[2]][PlaneY[1]] = '_';
    Board[PlaneX[2]][PlaneY[2]] = '$';
    Board[PlaneX[2]][PlaneY[3]] = '_';
    Board[PlaneX[2]][PlaneY[4]] = '$';
}

void removeFire(int score)
{
    for (int i = 0; i < 33; i++)
    {
        if (Board[0][i] == '|')
        {
            Board[0][i] = ' ';
            Board[1][i] = ' ';
            Board[2][i] = ' ';
        }
    }

    for (int i = 0; i < 33; i++)
    {
        if (Board[23][i] == '!')
        {
            Board[23][i] = ' ';
            if (score > 28)
                Board[22][i] = ' ';
        }
    }
}

void generateEnemies(int score, int health)
{
    int randomX = 0, randomY = 0;

    if (score < 30)
    {
        do
        {
            randomX = rand() % 5;
            randomY = rand() % 30;
        } while (Board[randomX][randomY] == '#' || randomY < 2 || randomY > 30 || (randomY + 1) % 3 == 0);
        randomX++;
        randomY++;

        Board[randomX][randomY] = '#';
        enemyFire(randomX + 1, randomY);
    }
    else
    {
        for (int i = 0; i < 24; i++)
        {
            for (int j = 0; j < 33; j++)
            {
                Board[i][j] = ' ';
            }
        }

        do
        {
            randomX = rand() % 5;
            randomY = rand() % 29;
        } while (Board[randomX][randomY] == '#' || randomY < 2);

        for (int i = randomX; i < randomX + 2; i++)
        {
            for (int j = randomY; j < randomY + 4; j++)
            {
                Board[i][j] = '#';
                enemyFire(i + 1, j);
            }
            // updateEnemyFire(score, health);
        }
    }
}

void generateGifts()
{
    int randomX = 0, randomY = 0;

    do
    {
        randomX = rand() % 5;
        randomY = rand() % 29;
    } while (Board[randomX][randomY] == '#' || randomY < 2 || randomY > 30 || Board[randomX][randomY] == '!');

    Board[randomX][randomY] = '+';
}

int countEnemies()
{
    int enemies = 0;
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 33; j++)
        {
            if (Board[i][j] == '#')
            {
                enemies++;
            }
        }
    }
    return enemies;
}

int countGifts()
{
    int gifts = 0;
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 33; j++)
        {
            if (Board[i][j] == '+')
            {
                gifts++;
            }
        }
    }
    return gifts;
}

void Move(int n, int &health)
{
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 33; j++)
        {
            if (Board[i][j] != '#' && Board[i][j] != '!' && Board[i][j] != '|' && Board[i][j] != '+')
            {
                Board[i][j] = ' ';
            }
        }
    }

    if (n == 0)
    {
        Board[PlaneX[0] - 1][PlaneY[2]] = '|';
        Board[PlaneX[0] - 2][PlaneY[2]] = '|';
        Board[PlaneX[0] - 3][PlaneY[2]] = '|';
    }

    if (n == 2)
    {
        for (int i = 0; i < 3; i++)
        {
            if (PlaneX[2] < 23)
            {
                PlaneX[i] += 1;
            }
        }
    }
    if (n == 4)
    {
        for (int j = 4; j >= 0; j--)
        {
            if (PlaneY[0] > 0)
            {
                PlaneY[j] -= 1;
            }
        }
    }
    if (n == 6)
    {
        for (int j = 0; j < 5; j++)
        {
            if (PlaneY[4] < 32)
            {
                PlaneY[j] += 1;
            }
        }
    }
    if (n == 8)
    {
        for (int i = 2; i >= 0; i--)
        {
            if (PlaneX[0] > 6)
            {
                PlaneX[i] -= 1;
            }
        }
    }
}

int main()
{
    int score = 0, health = 10;
    srand(time(0));

    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 33; j++)
        {
            Board[i][j] = ' ';
        }
    }

    plane(health);
    while (health > 0)
    {
        if (countEnemies() <= 3)
            generateEnemies(score, health);
        if (countGifts() != 1)
            generateGifts();
        Game(score, health);
        updateplaneFire(score);

        if (_kbhit())
        {
            switch (_getch())
            {
            case ' ':
                Move(0, health);
                break;
            case 72:
                Move(8, health);
                break;
            case 75:
                Move(4, health);
                break;
            case 77:
                Move(6, health);
                break;
            case 80:
                Move(2, health);
                break;
            }
        }

        plane(health);
        removeFire(score);
        updateEnemyFire(score, health);
        updateGifts(score, health);
        system("cls");
    }
    cout << "\n\n\n\n\n\t\t\t\"Game Over\"" << endl;
}