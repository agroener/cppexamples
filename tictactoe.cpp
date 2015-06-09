//6.5 Tic Tac Toe - C++ Programming For The Absolute Beginner

#include <iostream>
#include <string>

using std::string;

enum SquareState {blank = ' ', X = 'X', O='O'};

class GameBoard
{
private:
  const int WIDTH;
  const int HEIGHT;
  int* gameBoard;
public:
  GameBoard() : WIDTH(3), HEIGHT(3)
  {
    gameBoard = new int[9];
    for (int i=0; i<9; i++)
      *(gameBoard + i) = blank;
  }

  ~GameBoard() {delete[] gameBoard;}
  void setX(int h, int w);
  void setO(int h, int w);
  bool isTaken(int h, int w);
  SquareState isLine();
  void draw();
};

void GameBoard::setX(int h, int w)
{
  *(gameBoard + h*HEIGHT + w) = X;
}

void GameBoard::setO(int h, int w)
{
  *(gameBoard + h*HEIGHT + w) = O;
}

bool GameBoard::isTaken(int h, int w)
{
  return *(gameBoard + h*HEIGHT + w) != ' ';
}

SquareState GameBoard::isLine()
{
  if (*gameBoard==X && *(gameBoard+1)==X && *(gameBoard+2)==X)
    return X;
  if (*gameBoard==O && *(gameBoard+1)==O && *(gameBoard+2)==O)
    return O;
  if (*(gameBoard+3)==X && *(gameBoard+4)==X && *(gameBoard+5)==X)
    return X;
  if (*(gameBoard+3)==O && *(gameBoard+4)==O && *(gameBoard+5)==O)
    return O;
  if (*(gameBoard+6)==X && *(gameBoard+7)==X && *(gameBoard+8)==X)
    return X;
  if (*(gameBoard+6)==O && *(gameBoard+7)==O && *(gameBoard+8)==O)
    return O;
  if (*gameBoard==X && *(gameBoard+3)==X && *(gameBoard+6)==X)
    return X;
  if (*gameBoard==O && *(gameBoard+3)==O && *(gameBoard+6)==O)
    return O;
  if (*(gameBoard+1)==X && *(gameBoard+4)==X && *(gameBoard+7)==X)
    return X;
  if (*(gameBoard+1)==O && *(gameBoard+4)==O && *(gameBoard+7)==O)
    return O;
  if (*(gameBoard+2)==X && *(gameBoard+5)==X && *(gameBoard+8)==X)
    return X;
  if (*(gameBoard+2)==O && *(gameBoard+5)==O && *(gameBoard+8)==O)
    return O;
  if (*gameBoard==X && *(gameBoard+4)==X && *(gameBoard+8)==X)
    return X;
  if (*gameBoard==O && *(gameBoard+4)==O && *(gameBoard+8)==O)
    return O;
  if (*(gameBoard+2)==X && *(gameBoard+4)==X && *(gameBoard+6)==X)
    return X;
  if (*(gameBoard+2)==O && *(gameBoard+4)==O && *(gameBoard+6)==O)
    return O;
  return blank;
}

void GameBoard::draw()
{
  using std::cout;
  cout << "\n";
  for (int i=0; i< HEIGHT; i++)
    {
      cout << (char)*(gameBoard + i*HEIGHT);
      for (int c=1; c< WIDTH; c++)
        {
          cout << " | " << (char)*(gameBoard + i*WIDTH + c);
        }
      cout << "\n" << "-------" << "\n";
    }
}

class Game
{
public:
  GameBoard* doInput(string player,  GameBoard* gb);
  bool inRange(int test);
};

GameBoard* Game::doInput(string player, GameBoard* gb)
{
  using std::cout;
  using std::cin;

  gb->draw();
  string letter;
  if (player.compare("one") == 0)
    letter = "X";
  else if (player.compare("two") == 0)
    letter = "O";
  else return gb;

  int input1, input2;
  do {
    do {
    cout << "\nPlayer " << player.c_str()
         << ", please enter a row number to put an "
         << letter.c_str() << ": ";
    cin >> input1;
    } while(!inRange(input1));
    do {
      cout << "\nPlease enter a column number to put an "
           << letter.c_str() << ": ";
      cin >> input2;
    } while(!inRange(input2));
    
  } while (gb -> isTaken(input1, input2));

  if (player.compare("one") == 0)
    gb -> setX(input1,input2);
  else
    gb -> setO(input1,input2);
  return gb;
}

bool Game::inRange(int test)
{
  return test > -1 && test < 3;
}



int main(void)
{

  using std::cout;
  using std::cin;

  GameBoard* gb = new GameBoard;
  Game g;
  string player1, player2;
  cout << "Welcome to Tic Tac Toe!"
       << "\nPlayer one, please enter your name: ";
  cin >> player1;
  cout << "\nPlayer two, please enter your name: ";
  cin >> player2;

  while (gb -> isLine() == ' ')
    {
      gb = g.doInput("one",gb);
      gb = g.doInput("two",gb);
    }
  gb -> draw();
  if(gb->isLine() == X)
    cout << "\nPlayer one, you win!\nGame Over.";
  else
    cout << "\nPlayer two, you win!\nGame Over.";
  
  
  return 0;
}
