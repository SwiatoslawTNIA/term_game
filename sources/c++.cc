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
typedef struct _win_border_struct {
	chtype 	ls, rs, ts, bs, 
	 	tl, tr, bl, br;
}WIN_BORDER;

typedef struct Win_struct
{
   int startx, starty;
   int height, width;
   WIN_BORDER border;
}WIN;



void print_win_params(WIN *p_win)
{
#ifdef _DEBUG
	mvprintw(25, 0, "%d %d %d %d", p_win->startx, p_win->starty, 
				p_win->width, p_win->height);
	refresh();
#endif
}

//create a window + manipulate it, quiting when the keyword q is pressed:
void create_box(WIN * pointer, bool flag);
void destroy_w(WINDOW *p);
WINDOW *create_w(int height, int width, int start_y, int start_x);
void init_win_params(WIN *p_win);
int main(void)
{
   WIN win;
   int y = 0, x = 0, height = 5, width = 10, c;//c for input chars
   initscr();

  
   raw();
   noecho();
   start_color();		
   	/* Start the color functionality */
   
   
   refresh();
   clear();

   init_pair(1, COLOR_CYAN, COLOR_BLACK);
   getmaxyx(stdscr, y, x);
   keypad(stdscr, TRUE);//DO NOT FORGET!!!!!!
   attron(COLOR_PAIR(1));
   char s[] = "Press any arrow to move the box. q to quit";
   mvprintw(y / 2, (x - strlen(s)) / 2, "%s", s);//print the string
   attroff(COLOR_PAIR(1));
   getch();
   clear();//clear the screen
   refresh();
   // WINDOW * new_win = create_w(height, width, y, x);
   init_win_params(&win);
   print_win_params(&win);
   refresh();
   create_box(&win, TRUE);
   while((c = getch()) != 'q' && c != 'Q')
   {
      switch(c)
      {
         // case KEY_LEFT:
         // {
         //    create_box(&win, FALSE);
         //    if(win.startx > 0)
         //       --win.startx;
         //    create_box(&win, TRUE);
         //    break;
         // }
         // case KEY_RIGHT:
         // {
         //    create_box(&win, FALSE);
         //    if(win.startx  + win.width  + 1 < x)
         //       ++win.startx;
         //    create_box(&win, TRUE);
         //    break;
         // }
         // case KEY_UP:
         // {
         //    create_box(&win, FALSE);
         //    if(win.starty > 0)
         //       --win.starty;
         //    create_box(&win, TRUE);
         //    break;
         // }
         // case KEY_DOWN:
         // {
         //    create_box(&win, FALSE);
         //    if(win.starty + win.height + 1 < y)
         //       ++win.starty;
         //    create_box(&win, TRUE);
         //    break;
         // }
         case KEY_LEFT://speed x2
         {
            create_box(&win, FALSE);
            if(win.startx  - 1 > 0)
               win.startx -= 2;
            create_box(&win, TRUE);
            break;
         }
         case KEY_RIGHT:
         {
            create_box(&win, FALSE);
            if(win.startx  + win.width  + 2 < x)
               win.startx += 2;
            create_box(&win, TRUE);
            break;
         }
         case KEY_UP:
         {
            create_box(&win, FALSE);
            if(win.starty  - 1 > 0)
               win.starty -= 2;
            create_box(&win, TRUE);
            break;
         }
         case KEY_DOWN:
         {
            create_box(&win, FALSE);
            if(win.starty + win.height + 2 < y)
               win.starty += 2;
            create_box(&win, TRUE);
            break;
         }
      }
   }
   endwin();
   return 0;
}
WINDOW *create_w(int height, int width, int start_y, int start_x)
{
   WINDOW *w = newwin(height, width, start_y, start_x);
   init_pair(2, COLOR_RED, COLOR_BLUE);
   attron(COLOR_PAIR(2));

   box(w, 0,0);//set the default chars for vertial and horizontal lines
  
   wrefresh(w);//refresh the window
   attroff(COLOR_PAIR(2));
   return w;
}
void destroy_w(WINDOW *p)
{
   wborder(p, '|', '|', '-', '-', '+', '+', '+', '+');//set the border
   wrefresh(p);
   delwin(p);//delete the window
}


void init_win_params(WIN *p_win)
{
	p_win->height = 3;
	p_win->width = 10;
	p_win->starty = (LINES - p_win->height)/2;	
	p_win->startx = (COLS - p_win->width)/2;

	p_win->border.ls = '|';
	p_win->border.rs = '|';
	p_win->border.ts = '-';
	p_win->border.bs = '-';
	p_win->border.tl = '+';
	p_win->border.tr = '+';
	p_win->border.bl = '+';
	p_win->border.br = '+';

}



void create_box(WIN * pointer, bool flag)
{
   int i, j, x, y, w, h;

   x = pointer->startx;
   y = pointer->starty;
   w = pointer->width;
   h = pointer->height;

   if(flag)
   {
      init_pair(3, COLOR_RED, COLOR_GREEN);
      attron(COLOR_PAIR(3));
      mvaddch(y, x, pointer->border.tl);
      mvaddch(y, x + w, pointer->border.tr);
      mvaddch(y + h,x, pointer->border.bl);
      mvaddch(y + h, x  + w , pointer->border.br);


      mvhline(y, x + 1, pointer->border.ts, w - 1);
      mvhline(y + h, x + 1, pointer->border.ts, w - 1);
      mvvline(y + 1, x, pointer->border.ls, h - 1);
      mvvline(y + 1, x + w, pointer->border.rs, h  - 1);
      attroff(COLOR_PAIR(3));

   }
   else
   {//clear the rectangle [x, y, x + h, y + y]
      // for(i = y; i <= y + h; ++i)
      // {
      //    for(j = x; j <= x + w; ++j)
      //    {
      //       mvaddch(y, x, ' ');
      //    }
      // }
      clear();
   }
   refresh();//refresh
}