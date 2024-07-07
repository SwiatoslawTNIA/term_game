printw(string);        /* Print on stdscr at present cursor position */
    mvprintw(y, x, string);/* Move to (y, x) then print string     */
    wprintw(win, string);  /* Print on window win at present cursor position */
                           /* in the window */
    mvwprintw(win, y, x, string);   /* Move to (y, x) relative to window */
                                    /* co-ordinates and then print         */
  using namespace std;
  // initscr();
  // printw("Hello World.");//the data from here is written to the imaginary window, call refersh to flush the buffer
  // raw();//specifies that each char should be taken separately.
  // noecho();//do not show the chars typed
  // refresh();
  // getch();//wait for user input
  // keypad(stdscr, TRUE);//enables arrows reading
  // endwin();//frees the memory for the curses mode
  initscr();
  raw();//disable line buffering
  noecho();//do not display printed chars
  keypad(stdscr, TRUE);
  printw("Press any char");
  char c = getch();
  if(c == KEY_F(1))
    std::cout << "You pressed F1";
  else
    {
      printw("The word in bold: ");
      attron(A_BOLD);
      printw("%c", c);//can be used the same as printf
      attroff(A_BOLD);//set the attribute on/off
    }
  refresh();
  getch();//wait for user input
  endwin();



//funcs take y and then x coords

mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);//move to a location, +printf() func

  getmaxyx(stdscr,row,col);		/* get the number of rows and columns */


   addch(ch | A_BOLD | A_UNDERLINE);//print the char underlined + bald;
    mvaddch(y, x, ch);//move to and print char


   getyx(stdscr, y, x);		/* get the current curser position */
   clear();//clear the screen




   init_pair(1, COLOR_CYAN, COLOR_BLACK);
	printw("A Big string which i didn't care to type fully ");
	mvchgat(0, 0, -1, A_BLINK, 1, NULL);	
	/* 
	 * First two parameters specify the position at which to start 
	 * Third parameter number of characters to update. -1 means till 
	 * end of line
	 * Forth parameter is the normal attribute you wanted to give 
	 * to the charcter
	 * Fifth is the color index. It is the index given during init_pair()
	 * use 0 if you didn't want color
	 * Sixth one is always NULL 
	 */
 

// he following program uses mvhline() and mvvline() to achieve similar effect. 
// These two functions are simple. They create a horizontal or vertical line of 
//the specified length at the specified position.


  start_color();			/* Start the color functionality */
  init_pair(1, COLOR_CYAN, COLOR_BLACK);

  // 1: This is the pair number or index. In ncurses, color pairs are indexed starting 
  // from 1. This index is used to refer to the color pair 
  // when you want to apply it to text or background using attron() or attrset() functions.
  attron(COLOR_PAIR(1));
	printw("Press F1 to exit");
	refresh();
	attroff(COLOR_PAIR(1));


  mvaddch(y, x, p_win->border.tl);//moves + adds a char
		mvaddch(y, x + w, p_win->border.tr);
		mvaddch(y + h, x, p_win->border.bl);
		mvaddch(y + h, x + w, p_win->border.br);
		mvhline(y, x + 1, p_win->border.ts, w - 1);//creates a horizontal line
		mvhline(y + h, x + 1, p_win->border.bs, w - 1);
		mvvline(y + 1, x, p_win->border.ls, h - 1);//creates a vertical line
		mvvline(y + 1, x + w, p_win->border.rs, h - 1);