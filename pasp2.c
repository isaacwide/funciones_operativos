#include<ncurses.h>

int main(){
	char cadena[128];
	initscr();
	erase();
	printw("dame tu pasword=");
	noecho();
	scanw("%s",cadena);
	echo();
	/*move(12,30:)*/
	mvprintw(12,30,"tu pasword es = %s",cadena);
	refresh();
	getch();
	endwin();
	return 0;






}
