#include<ncurses.h>

int main(){
    char cadena[128];
    initscr();
    printw("give me your name fucker");
    scanw("%s",cadena);
    printw("your name is = %s",cadena);


    refresh();
   getch();

   endwin();
   return 0;



}
