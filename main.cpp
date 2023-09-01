#include <iostream>
#include <ctime>

void board(char *spaces);
void playerMark(char *spaces, char player);
void computerMark(char *spaces, char computer);
bool chooseWinner(char *spaces, char player, char computer);
bool isTie(char *spaces);

int main()
{
  char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  char player = 'X';
  char computer = 'O';
  bool running = true;

  board(spaces);

  while (running)
  {
    playerMark(spaces, player);
    board(spaces);
    if (chooseWinner(spaces, player, computer))
    {
      running = false;
      break;
    }
    else if (isTie(spaces))
    {
      running = false;
      break;
    }

    computerMark(spaces, computer);
    board(spaces);
    if (chooseWinner(spaces, player, computer))
    {
      running = false;
      break;
    }
    else if (isTie(spaces))
    {
      running = false;
      break;
    }
  }
}

void board(char *spaces)
{
  std::cout << std::endl;
  std::cout << "     |     |     " << std::endl;
  std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << std::endl;
  std::cout << "_____|_____|_____\n";
  std::cout << "     |     |     " << std::endl;
  std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << std::endl;
  std::cout << "_____|_____|_____\n";
  std::cout << "     |     |     " << std::endl;
  std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << std::endl;
  std::cout << "     |     |     " << std::endl;
  std::cout << std::endl;
}

void playerMark(char *spaces, char player)
{
  int number;
  do
  {
    std::cout << "Enter a position (1-9) : ";
    std::cin >> number;
    number--;

    if (spaces[number] == ' ')
    {
      spaces[number] = player;
      break;
    }
  } while (!number > 0 || !number < 8);
}

void computerMark(char *spaces, char computer)
{
  int randNum = 0;
  srand(time(0));
  while (true)
  {
    randNum = rand() % 9;
    if (spaces[randNum] == ' ')
    {
      spaces[randNum] = computer;
      break;
    }
  }
}

bool chooseWinner(char *spaces, char player, char computer)
{
  if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
  {
    spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
  }
  else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))
  {
    spaces[3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
  }
  else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8]))
  {
    spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
  }
  else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6]))
  {
    spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
  }
  else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7]))
  {
    spaces[1] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
  }
  else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8]))
  {
    spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
  }
  else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))
  {
    spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
  }
  else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))
  {
    spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
  }
  else
  {
    return false;
  }

  return true;
}

bool isTie(char *spaces)
{
  for (int i = 0; i < 9; i++)
  {
    if (spaces[i] == ' ')
    {
      return false;
    }
    std::cout << "IT IS A TIE!";
    return true;
  }
}