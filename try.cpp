#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <deque>
using namespace std;

const int kMaxFood = 20;
// 胜利食用food数
const char kEmptyTile = ' ';
const char kWallTile = '#';
const char kFoodTile = '$';
const char kSnakeTile = '*';
const double kWaitTime = 1.0;
const string kClearCommand = "CLS";
const double kTUrnRate = 0.2;

struct Point
{
    int Row, Col;
};
// 坐标表示
struct GameT
{
    vector<string> world; // 场地信息
    int Row_Num, Col_Num; // 场地大小

    deque<Point> snake; // 蛇体
    int dx, dy;         // 前进方向

    int NumEaten; // 已获得food数
};
// 存储游戏结构信息

string GetLine();
Point MakePoint(int row, int col);
void LoadWorld(GameT &game, ifstream &input);
void OpenUserFile(ifstream &inout);
void InitializeGame(GameT &game);
void PrintWorld(GameT &game);
bool InWorld(Point &pt, GameT &game);
bool Crashed(Point headPots, GameT &game);
Point GetNextPosition(GameT &game, int dx, int dy);
bool RandomChance(double probability);
void PerformAI(GameT &game);
void PlaceFood(GameT &game);
bool MoveSnake(GameT &game);
void Pause();
void DisplayResult(GameT &game);
void RunSimulation(GameT game);

int main(void)
{
    GameT game;
    InitializeGame(game);
    RunSimulation(game);
    return 0;
}

string GetLine()
{
    string result;
    getline(cin, result);
    return result;
}
Point MakePoint(int row, int col)
{
    Point head;
    head.Row = row;
    head.Col = col;
    return head;
}
void LoadWorld(GameT &game, ifstream &input)
{
    input >> game.Row_Num >> game.Col_Num;
    game.world.resize(game.Row_Num);

    input >> game.dx >> game.dy;

    string dummy;
    getline(input, dummy);

    for (int row = 0; row < game.Row_Num; ++row)
    {
        getline(input, game.world[row]);
        int col = game.world[row].find(kSnakeTile);
        if (col != string::npos)
        {
            game.snake.push_back(MakePoint(row, col));
        }
    }

    game.NumEaten = 0;
}
void OpenUserFile(ifstream &input)
{
    while (true)
    {
        cout << "enter filename:" << endl;
        string filename = GetLine();

        input.open(filename.c_str());
        if (input.is_open())
        {
            break;
        }
        else
        {
            cout << "sorry, can't open the file" << endl;
            input.clear();
        }
    }
}
void InitializeGame(GameT &game)
{
    srand(static_cast<unsigned int>(time(NULL)));
    ifstream input;
    OpenUserFile(input);
    LoadWorld(game, input);
}
void PrintWorld(GameT &game)
{
    system(kClearCommand.c_str());
    for (int row = 0; row < game.Row_Num; ++row)
    {
        cout << game.world[row] << endl;
    }
    cout << "Food Eaten: " << game.NumEaten << endl;
}
Point GetNextPosition(GameT &game, int dx, int dy)
{
    Point result = game.snake.front();

    result.Row += game.dy;
    result.Col += game.dx;
    return result;
}
bool InWorld(Point &pt, GameT &game)
{
    return pt.Col >= 0 && pt.Row >= 0 && pt.Col < game.Col_Num && pt.Row < game.Row_Num;
}
bool Crashed(Point headPos, GameT &game)
{
    return !InWorld(headPos, game) || game.world[headPos.Row][headPos.Col] == kSnakeTile || game.world[headPos.Row][headPos.Col] == kWallTile;
}
bool RandomChance(double probability)
{
    return (rand() / (RAND_MAX + 1.0)) < probability;
}
void PerformAI(GameT &game)
{
    Point nextHead = GetNextPosition(game, game.dx, game.dy);

    if (Crashed(nextHead, game) || RandomChance(kTUrnRate))
    {
        int leftDx = -game.dy;
        int leftDy = game.dx;

        int rightDx = game.dy;
        int rightDy = -game.dx;

        bool canLeft = !Crashed(GetNextPosition(game, leftDx, leftDy), game);
        bool canRight = !Crashed(GetNextPosition(game, rightDx, rightDy), game);

        bool willTurnLeft = false;
        if (!canLeft && !canRight)
        {
            return;
        }
        else if (canLeft && !canRight)
        {
            willTurnLeft = true;
        }
        else if (!canLeft && canRight)
        {
            willTurnLeft = false;
        }
        else
        {
            willTurnLeft = RandomChance(0.5);
        }

        game.dx = willTurnLeft ? leftDx : rightDx;
        game.dy = willTurnLeft ? leftDy : rightDy;
    }
}
void PlaceFood(GameT &game)
{
    while (true)
    {
        int row = rand() % game.Row_Num;
        int col = rand() % game.Col_Num;

        if (game.world[row][col] == kEmptyTile)
        {
            game.world[row][col] = kFoodTile;
            return;
        }
    }
}
bool MoveSnake(GameT &game)
{
    Point nextHead = GetNextPosition(game, game.dx, game.dy);
    if (Crashed(nextHead, game))
    {
        return false;
    }

    bool isFood = (game.world[nextHead.Row][nextHead.Col] == kFoodTile);

    game.world[nextHead.Row][nextHead.Col] = kSnakeTile;
    game.snake.push_front(nextHead);

    if (!isFood)
    {
        game.world[game.snake.back().Row][game.snake.back().Col] = kEmptyTile;
        game.snake.pop_back();
    }
    else
    {
        ++game.NumEaten;
        PlaceFood(game);
    }
    return true;
}
void Pause()
{
    clock_t startTime = clock();

    while (static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC <
           kWaitTime)
    {
        ;
    }
}
void DisplayResult(GameT &game)
{
    PrintWorld(game);
    if (game.NumEaten == kMaxFood)
    {
        cout << "the snake ate enough food and wins" << endl;
    }
    else
    {
        cout << "the snake crashed" << endl;
    }
}
void RunSimulation(GameT game)
{
    while (game.NumEaten < kMaxFood)
    {
        PrintWorld(game);
        PerformAI(game);

        if (!MoveSnake(game))
        {
            break;
        }

        Pause();
    }
    DisplayResult(game);
}