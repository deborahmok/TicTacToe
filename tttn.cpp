// NxN tic-tac-toes
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// The following 3 functions are helper functions to convert
// between 1D and 2D array indices.  The grid itself is stored
// as a 1D array.  However, for printing, checking who won,
// etc. it may be easier to write loops that generate separate
// row/column indices (i.e. treating the array like a 2D array).
// The functions below should be written using the hints in the
// writeup for performing the appropriate arithmetic conversion
// between 1D- and 2D-indices, and can then be called in any
// of the other functions when you find yourself wanting to
// convert one to the other.

/**
 * Helper function - Given the grid array and its dimension
 *    as well as a particular row (r) and column (c), this
 *    function performs the arithmetic to convert r and c
 *    to a 1D index and returns that character in the grid.
 *    For example, for dim = 3 and r = 2, c = 1, this function
 *    should compute the corresponding index: 7 and return
 *    grid[7].
 *
 * Use this function wherever you generate, row/column
 *    indices and want to access that element in the grid.
 *    Pass the row/column indices as r and c, respectively.
 *
 */
char getEntryAtRC(char grid[], int dim, int r, int c); //done

/**
 * Helper function - Given a 1D index returns the row
 * that corresponds to this 1D index.  Use this in
 * conjunction with idxToCol() anytime you have a 1D index
 * and want to convert to 2D indices.
 */
int idxToRow(int idx, int dim); //done

/**
 * Helper function - Given a 1D index returns the column
 * that corresponds to this 1D index.  Use this in
 * conjunction with idxToRow() anytime you have a 1D index
 * and want to convert to 2D indices.
 */
int idxToCol(int idx, int dim); //done


/** Should print the tic-tac-toe board in a nice grid
 *  format as shown below:
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O'
 *         (the letter oh), or '?'.
 */
void printTTT(char grid[], int dim); //done

/**
 * Should check if any player has won the game yet.
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O', or '?'
 *
 * Return value:
 *   Should return 1 if 'X' has won, 2 if 'O' has won, or 0 (zero)
 *   if the game is still undecided.
 *
 */
int checkForWinner(char grid[], int dim); 


/**
 * Should check if there is no possible way any player can win.
 * More specifically, if there does not exist a row, column,
 * or diagonal that can still have 3 of a kind, then the game
 * will be a draw.
 *
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O', or '?'
 *
 * Return value:
 *   Return true if no player can win given the current
 *   game state, false otherwise.
 */
bool checkForDraw(char grid[], int dim);

/**
 * @brief Get the Ai Choice for the current player and update grid object
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O', or '?'
 *   dim: the dim(-ension) of the tic-tac-toe board
 *   player: current player => 'X' or 'O'
 * @return true If an error occurred or a choice was unable to be made
 * @return false If a play was successfully made
 */
bool getAiChoiceAndUpdateGrid(char grid[], int dim, char player);

/**
 * @brief Picks a random location for the current player and update grid
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O', or '?'
 *   dim: the dim(-ension) of the tic-tac-toe board
 *   player: current player => 'X' or 'O'
 * @return true If no viable location to be played
 * @return false If a play was successfully made
 */
bool getRandChoiceAndUpdateGrid(char grid[], int dim, char player);


/**********************************************************
 *  Write your implementations for each function prototyped
 *  above in the space below
 **********************************************************/

char getEntryAtRC(char grid[], int dim, int r, int c)
{
  return grid[dim*r+c];
}

int idxToRow(int idx, int dim)
{
  return idx/dim;
}

int idxToCol(int idx, int dim)
{
  return idx%dim;
}

void printTTT(char grid[], int dim) 
{
  for (int i = 0; i < dim; i++) //checks the row
  {
    for (int j = 0; j < dim; j++) //checks the column
    {
      if (j == 0) //to have no '|' in the first character on the main left
      {
        cout << " " << grid[i*dim+j] << " | ";
      }
      else if (j == dim - 1) //for the scenario at the main right
      {
        cout << grid[i*dim+j];
      }
      else 
      {
        cout << grid[i*dim+j] << " | ";
      }
    }
    cout << endl;
    if (i != dim - 1) //not for the scenario of the last character
    {
      for (int g = 0; g < 4*dim-1; g++)
      {
        cout << "-";
      }
      cout << endl;
    }
  }
}

int checkForWinner(char grid[], int dim) 
{
  //checks the row
  for (int i = 0; i < dim; i++)
  {
    int check_x = 0; //renew all the amount of X and O
    int check_o = 0; 
    for (int j = 0; j < dim; j++) 
    {
      if (getEntryAtRC(grid,dim,i,j) == 'X')
      {
        check_x += 1;
      }
      else if (getEntryAtRC(grid,dim,i,j) == 'O')
      {
        check_o += 1;
      }
    }
    if (check_x == dim) 
    {
      return 1;
    }
    else if (check_o == dim)
    {
      return 2;
    }
  }

  //checks the column
  for (int i = 0; i < dim; i++)
  {
    int check_x = 0; 
    int check_o = 0;
    for (int j = 0; j < dim; j++) 
    {
      if (getEntryAtRC(grid,dim,j,i) == 'X')
      {
        check_x += 1;
      }
      else if (getEntryAtRC(grid,dim,j,i) == 'O')
      {
        check_o += 1;
      }
    }
    if (check_x == dim)
    {
      return 1;
    }
    else if (check_o == dim)
    {
      return 2;
    }
  }

  //checks the diagonal 1: top-left to bottom-right
  int check_x = 0; 
  int check_o = 0; 
  for (int j = 0; j < dim_sq; j += (dim + 1)) //j=j+dim+1 //treating as a 1D array
  {
    if (grid[j] == 'X') 
    {
      check_x += 1;
    }
    if (grid[j] == 'O') 
    {
      check_o += 1;
    }
  }
  if (check_x == dim)
  {
    return 1;
  }
  else if (check_o == dim)
  {
    return 2;
  }

  //checks the diagonal 2: top-right to bottom-left diagonal
  check_x = 0; 
  check_o = 0;
  int row = 0;
  for (int i = dim - 1; i >= 0; i--)
  {
    if (getEntryAtRC(grid,dim,row,i) == 'X') //dim*r+c
    {
      check_x += 1;
    }
    else if (getEntryAtRC(grid,dim,row,i) == 'O')
    {
      check_o += 1;
    } 
    row++;
  }
  if (check_x == dim)
  {
    return 1;
  }
  else if (check_o == dim)
  {
    return 2;
  }
  return 0;
}

bool checkForDraw(char grid[], int dim)
{
  bool draw = false;
  //winner-not a draw
  //empty-not a draw
  //X and O on a line then a draw

  //checks the row
  int counter = 0;
  for (int i = 0; i < dim; i++)
  {
    int check_x = 0; 
    int check_o = 0;
    for (int j = 0; j < dim; j++) 
    {
      if (getEntryAtRC(grid,dim,i,j) == 'X')
      {
        check_x += 1;
      }
      else if (getEntryAtRC(grid,dim,i,j) == 'O')
      {
        check_o += 1;
      }
    }
    if (check_x && check_o) //if there is X and O at the same line
    {
      counter++;
    }
    if (check_x == dim) //if there is a winning scenario
    {
      draw = false;
    }
    else if (check_o == dim)
    {
      draw = false;
    }
  }

  //checks the column
  for (int i = 0; i < dim; i++)
  {
    int check_x = 0; 
    int check_o = 0;
    for (int j = 0; j < dim; j++) 
    {
      if (getEntryAtRC(grid,dim,j,i) == 'X')
      {
        check_x += 1;
      }
      else if (getEntryAtRC(grid,dim,j,i) == 'O')
      {
        check_o += 1;
      }
    }
    if (check_x && check_o)
    {
      counter++;
    }
    if (check_x == dim)
    {
      draw = false;
    }
    else if (check_o == dim)
    {
      draw = false;
    }
  }

  //checks the diagonal 1: top-left to bottom-right
  int check_x = 0; 
  int check_o = 0; 
  for (int j = 0; j < pow(dim,2); j+=(dim+1)) //j=j+dim+1 //treating as a 1D array
  {
    if (grid[j] == 'X')
    {
      check_x += 1;
    }
    else if (grid[j] == 'O')
    {
      check_o += 1;
    }
  }
  if (check_x && check_o)
  {
    counter++;
  }
  if (check_x == dim)
  {
    draw = false;
  }
  else if (check_o == dim)
  {
    draw = false;
  }
  

  //checks the diagonal 2: top-right to bottom-left diagonal
  check_x = 0; 
  check_o = 0;
  for (int i = dim - 1; i >= 0; i--)
  {
    if (getEntryAtRC(grid,dim,i,i) == 'X')
    {
      check_x += 1;
    }
    else if (getEntryAtRC(grid,dim,i,i) == 'O')
    {
      check_o += 1;
    } 
  }
  if (check_x && check_o)
  {
    counter++;
  }
  if (check_x == dim)
  {
    draw = false;
  }
  else if (check_o == dim)
  {
    draw = false;
  }

  if (counter == 2*dim+2) //if there is counter in every case scenario, then it is a draw
  {
    draw = true;
  }
  return draw;
}

bool getAiChoiceAndUpdateGrid(char grid[], int dim, char player)
{
  int playerInt = 0;
  int opponentInt = 0;
  if (player == 'X')
  {
    playerInt = 1;
    opponentInt = 2;
  }
  else 
  {
    playerInt = 2;
    opponentInt = 1;
  }
  for (int i = 0; i < dim_sq; i++)
  {
    if (grid[i] == '?')
    {
      grid[i] = player;
      if (checkForWinner(grid, dim) == playerInt) //scenario for WIN
      {
        return false;
      }

      //intializing what the opponent's char
      char opponents = '-';
      if (player == 'X')
      {
        opponents = 'O';
      }
      else 
      {
        opponents = 'X';
      }

      grid[i] = opponents; //change it to the opponents
      if (checkForWinner(grid, dim) == opponentInt) //check if the opponent wins
      {
        grid[i] = player;
        return false;
      }

      else //resetting the grid back to a ?
      {
        grid[i] = '?';
      }
    }
  }
  return true;
}


// Complete...Do not alter
bool getRandChoiceAndUpdateGrid(char grid[], int dim, char player)
{
  int start = rand()%(dim*dim);
  // look for an open location to play based on random starting location.
  // If that location is occupied, move on sequentially until wrapping and
  // trying all locations
  for(int i=0; i < dim*dim; i++) 
  {
    int loc = (start + i) % (dim*dim);
    if(grid[ loc ] == '?') 
    {
      grid[ loc ] = player;
      return false;
    }
  }
  // No viable location
  return true;
}


/**********************************************************
 *  Complete the indicated parts of main(), below.
 **********************************************************/
int main()
{
  // This array holds the actual board/grid of X and Os. It is sized
  // for the biggest possible case (11x11), but you should only
  // use dim^2 entries (i.e. if dim=3, only use 9 entries: 0 to 8)
  char tttdata[121];

  // dim stands for dimension and is the side length of the
  // tic-tac-toe board i.e. dim x dim (3x3 or 5x5).
  int dim;
  int seed;
  // Get the dimension from the user
  cin >> dim >> seed;
  srand(seed);

  int dim_sq = dim*dim;

  for(int i=0; i < dim_sq; i++) 
  {
      tttdata[i] = '?';
  }

  // Print one of these messages when the game is over
  // and before you quit
  const char xwins_msg[] = "X player wins!";
  const char owins_msg[] = "O player wins!";
  const char draw_msg[] =  "Draw...game over!";

  bool done = false;
  char player = 'X';
  // Show the initial starting board
  printTTT(tttdata, dim);

  int idx;
  cout << "Player " << player << " enter your square choice [0-" << dim_sq-1 << "], -1 (AI), or -2 (Random): " << endl;
  cin >> idx;
  while(!done) 
  {
    if (idx == -1) //checking for AI
    {
      getAiChoiceAndUpdateGrid(tttdata, dim, player);
      printTTT(tttdata, dim);
      //checking for any winners
      if (checkForWinner(tttdata,dim) == 1)
      {
        cout << xwins_msg << endl;
        done = true;
        break;
      }
      else if (checkForWinner(tttdata,dim) == 2)
      {
        cout << owins_msg << endl; 
        done = true;
        break;
      }
      else
      {
        if (checkForDraw(tttdata, dim) == true)
        {
          cout << draw_msg << endl;
          done = true;
          break;
        }
      }
      if (player == 'X') //changing the player char
      {
        player = 'O';
      }
      else 
      {
        player = 'X';
      }
      cout << "Player " << player << " enter your square choice [0-" << dim_sq-1 << "], -1 (AI), or -2 (Random): " << endl;
      cin >> idx;
    }
    else if (idx == -2) //for the random choice
    {
      getRandChoiceAndUpdateGrid(tttdata, dim, player);
    }

    //for the [0-dim_sq] input
    bool asking_input = false;
    if (idx >= 0 && idx < dim_sq ) //if it's within range
    {
      asking_input = true;
    } 
    while (asking_input) //continue loop within range
    {
      if ((idx != -1) && (idx != -2) && (idx < 0 && idx >= dim_sq)) //for wrong input, quits game
      {
        done = true;
        break;
      }
      int r = idxToRow(idx,dim);
      int c = idxToCol(idx,dim);
      if (getEntryAtRC(tttdata, dim, r, c) == '?') //check if it's blank
      {
        tttdata[idx] = player; //set the position to the player's char
        printTTT(tttdata, dim);
        if (player == 'X')
        {
          player = 'O';
        }
        else 
        {
          player = 'X';
        }
        //checking if there's any winning scenario
        if (checkForWinner(tttdata,dim) == 1) 
        {
          cout << xwins_msg << endl;
          done = true;
          break;
        }
        else if (checkForWinner(tttdata,dim) == 2)
        {
          cout << owins_msg << endl; 
          done = true;
          break;
        }
        else
        {
          if (checkForDraw(tttdata, dim) == true)
          {
            cout << draw_msg << endl;
            done = true;
            break;
          }
        }
        //reask question
        cout << "Player " << player << " enter your square choice [0-" << dim_sq-1 << "], -1 (AI), or -2 (Random): " << endl;
        cin >> idx;
        //if not in the range
        if ((idx == -1) || (idx == -2) || (idx < 0 && idx >= dim_sq))
        {
          break;
        }
      }
      else //if the position is not blank
      {
        //reask
        cout << "Player " << player << " enter your square choice [0-" << dim_sq-1 << "], -1 (AI), or -2 (Random): " << endl;
        cin >> idx;
        if ((idx == -1) || (idx == -2) || (idx < 0 && idx >= dim_sq))
        {
          break;
        }
      }
      if ((idx != -1) && (idx != -2) && (idx < 0 && idx >= dim_sq)) //wrong input, quits game
      {
        done = true;
        break;
      }
    }
  }
  return 0;
}