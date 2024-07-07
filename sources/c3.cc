//---------------------------------------------------------------------------------------------------------------------
// c++.cc
//
// <This should be a simple terminal game>
//
//---------------------------------------------------------------------------------------------------------------------
//
#include "c++.h"
//---------------------------------------------------------------------------------------------------------------------
///
/// This is an example header comment. Here, you explain, what the
/// function does. Copypaste and adapt it!
///
/// @param numbers an array to check
/// @param length The length of the array. If this text is too long you can
///
/// @return the highest number
//
int main(int argc, char **argv)
{
  using namespace std;
   if(argc != 2)
   {
      std::cout << "Invalid input, exiting";
   }

  //the program reads from a file, and prints it :
  ifstream obj(argv[1]);
  if(!obj.is_open())
  {
   std::cerr << "Unable to open the file. terminating...";
   return 1;
  }
   char c;
   unsigned short int rows, cols;

   getmaxyx(stdscr, rows, cols);
   initscr();
   noecho();
   raw();
   while(obj.get(c))
   {
      int current_y = 0, current_x = 0;
      getyx(stdscr, current_y, current_x);
      if(current_y == (rows - 1))
      {
         //we're in the last row:
         printw("<-- Press any key to continue -->");
         getch();
         refresh();
         clear();
         move(0, 0); //move to the starting position
      }
      
      printw("%c", c);
      refresh();  
   }
   getch();//wait for the output

   clear();//clear the scree
   move(0, 0);
   printw("An extermely long and unattractive string.");
   mvchgat(0,0, -1, A_BLINK, 1, NULL);
   refresh();
   getch();//wati
   endwin();
   obj.close();
  return 0;
}