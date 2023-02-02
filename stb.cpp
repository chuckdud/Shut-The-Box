#include <string.h>
#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

char dot = 'o';

class Tile {
private:
	WINDOW *win;
	int val;
	int open;
	int selected;

public:
	Tile(int num) {
		val = num;
		open = 1;
		selected = 0;
		switch(num) {
			case 1:
				win = newwin(5, 5, 2, 3); 
				draw_box();
				mvwaddch(win, 1, 2, '1');
				wrefresh(win);
				break;
			case 2:
				win = newwin(5, 5, 2, 8); 
				draw_box();
				mvwaddch(win, 1, 2, '2');
				wrefresh(win);
				break;
			case 3:
				win = newwin(5, 5, 2, 13); 
				draw_box();
				mvwaddch(win, 1, 2, '3');
				wrefresh(win);
				break;
			case 4:
				win = newwin(5, 5, 2, 18); 
				draw_box();
				mvwaddch(win, 1, 2, '4');
				wrefresh(win);
				break;
			case 5:
				win = newwin(5, 5, 2, 23); 
				draw_box();
				mvwaddch(win, 1, 2, '5');
				wrefresh(win);
				break;
			case 6:
				win = newwin(5, 5, 2, 28); 
				draw_box();
				mvwaddch(win, 1, 2, '6');
				wrefresh(win);
				break;
			case 7:
				win = newwin(5, 5, 2, 33); 
				draw_box();
				mvwaddch(win, 1, 2, '7');
				wrefresh(win);
				break;
			case 8:
				win = newwin(5, 5, 2, 38); 
				draw_box();
				mvwaddch(win, 1, 2, '8');
				wrefresh(win);
				break;
			case 9:
				win = newwin(5, 5, 2, 43); 
				draw_box();
				mvwaddch(win, 1, 2, '9');
				wrefresh(win);
				break;
			case 10:
				win = newwin(5, 5, 2, 48); 
				draw_box();
				mvwprintw(win, 1, 2, "10");
				wrefresh(win);
				break;
			case 11:
				win = newwin(5, 5, 2, 53); 
				draw_box();
				mvwprintw(win, 1, 2, "11");
				wrefresh(win);
				break;
			case 12:
				win = newwin(5, 5, 2, 58); 
				draw_box();
				mvwprintw(win, 1, 2, "12");
				wrefresh(win);
				break;
			default:
				break;
		}
	}

	int draw_box() {
		mvwaddch(win, 0, 4, ACS_URCORNER);
		mvwaddch(win, 0, 0, ACS_ULCORNER);
		whline(win, 0, 3);
		mvwaddch(win, 2, 4, ACS_LRCORNER);
		mvwaddch(win, 2, 0, ACS_LLCORNER);
		whline(win, 0, 3);
		mvwaddch(win, 1, 0, ACS_VLINE);
		mvwaddch(win, 1, 4, ACS_VLINE);
		mvwprintw(win, 1, 2, "%d", val);
		return 0;
	}

	int hover() {
		if (!open) return 1;
		mvwaddch(win, 4, 2, '^');
		wrefresh(win);
		return 0;
	}

	int unhover() {
		mvwaddch(win, 4, 2, ' ');
		wrefresh(win);
		return 0;
	}

	int select() {
		if (!open) return 1;
		selected = 1;
		mvwaddch(win, 3, 2, 'X');
		wrefresh(win);
		return 0;
	}

	int unselect() {
		selected = 0;
		mvwaddch(win, 3, 2, ' ');
		wrefresh(win);
		return 0;
	}

	int shut() {
		if (!open) return 1;

		wclear(win);
		open = 0;
		wrefresh(win);
		return 0;
	}

	int _open() {
		draw_box();
		unselect();
		open = 1;
		return 0;
	}

	int get_val() {
		return val;
	}

	int is_open() {
		return open;
	}

	int is_selected() {
		return selected;
	}
};

class Die {
public:
	WINDOW *win;
	int val;
	int saved;

	Die(int num) {
		val = rand() % 6 + 1;
		saved = 0;
		switch(num) {
			case 1:
				win = newwin(5, 5, 9, 28);
				break;
			case 2:
				win = newwin(5, 5, 9, 33);
				break;
			default:
				std::cout << "Error creating die window" << std::endl;
				break;
		}
	}
	
	int roll() {
		val = rand() % 6 + 1;
		return val;
	}

	int print() {
		wclear(win);
		box(win, 0, 0);
		switch(val) {
			case 1:
				mvwaddch(win, 2, 2, dot);
				break;
			case 2:
				mvwaddch(win, 1, 3, dot);
				mvwaddch(win, 3, 1, dot);
				break;
			case 3:
				mvwaddch(win, 1, 3, dot);
				mvwaddch(win, 2, 2, dot);
				mvwaddch(win, 3, 1, dot);
				break;
			case 4:
				mvwaddch(win, 1, 1, dot);
				mvwaddch(win, 1, 3, dot);
				mvwaddch(win, 3, 1, dot);
				mvwaddch(win, 3, 3, dot);
				break;
			case 5:
				mvwaddch(win, 1, 1, dot);
				mvwaddch(win, 1, 3, dot);
				mvwaddch(win, 2, 2, dot);
				mvwaddch(win, 3, 1, dot);
				mvwaddch(win, 3, 3, dot);
				break;
			case 6:
				mvwaddch(win, 1, 1, dot);
				mvwaddch(win, 1, 3, dot);
				mvwaddch(win, 2, 1, dot);
				mvwaddch(win, 2, 3, dot);
				mvwaddch(win, 3, 1, dot);
				mvwaddch(win, 3, 3, dot);
				break;
			default:
				break;
		}
		wrefresh(win);
		return 0;
	}

	~Die() {
	}
};

void init_display() {
	initscr();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	move(16, 0);
	hline(0, 80);
	mvprintw(17, 2, "SHUT THE BOX");
	mvprintw(19, 2, "Controls:");
	mvprintw(20, 6, "LEFT/RIGHT ARROW KEY - move cursor left/right");
	mvprintw(21, 6, "'x' - select a tile to shut");
	mvprintw(22, 6, "'r' - reset");
	mvprintw(23, 6, "'q' - quit");
	wrefresh(stdscr);

}

void end_display() {
	endwin();
}

int roll(Die *dice[2]) {
	for (int frames = 0; frames < 5; frames++) {
		for (int i = 0; i < 2; i++) {
			dice[i]->roll();
			dice[i]->print();
		}
		usleep(100000);
	}
	return 0;
}

int check_play(int shutters[12], int dice_sum) {
	int user_sum = 0;
	for (int i = 0; i < 12; i++) if (shutters[i] == 1) user_sum += i + 1;
	return user_sum - dice_sum;
}

int main(int argc, char *argv[]) {
	srand(time(0));

	init_display();

	WINDOW *board = newwin(7, 62, 1, 2);
	wborder(board, 0, 0, 0, 0, 0, 0, 0, 0);
	wrefresh(board);

	Tile tile1(1);
	Tile tile2(2);
	Tile tile3(3);
	Tile tile4(4);
	Tile tile5(5);
	Tile tile6(6);
	Tile tile7(7);
	Tile tile8(8);
	Tile tile9(9);
	Tile tile10(10);
	Tile tile11(11);
	Tile tile12(12);

	Tile *tiles[12] = {&tile1, &tile2, &tile3, &tile4, &tile5, &tile6, &tile7, &tile8, &tile9, &tile10, &tile11, &tile12};

	Die die0(1);
	Die die1(2);

	Die *dice[2] = {&die0, &die1};

	int shutters[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (Die *d : dice) d->print();

	int carat = 0;

	tiles[carat]->hover();

	int ch = getch();
	while (ch != 'q') {
		if (ch == KEY_LEFT) {
			for (int i = carat - 1; i >= 0; i--) {
				if (tiles[i]->is_open()) {
					tiles[carat]->unhover();
					carat = i;
					tiles[carat]->hover();
					break;
				}
			}
		} else if (ch == KEY_RIGHT) {
			for (int i = carat + 1; i < 12; i++) {
				if(tiles[i]->is_open()) {
					tiles[carat]->unhover();
					carat = i;
					tiles[carat]->hover();
					break;
				}
			}
		} else if (ch ==  'x' || ch == 'X') {
			if (tiles[carat]->is_selected()) {
				tiles[carat]->unselect();
				shutters[carat] = 0;
			}
			else {
				tiles[carat]->select();
				shutters[carat] = 1;
			}
		} else if (ch == 10) {
			int valid = check_play(shutters, die0.val + die1.val);
			if (valid == 0) {
				move(15, 0);
				clrtoeol();
				refresh();
				for (int i = 0; i < 12; i++) {
					if (shutters[i] == 1)  {
						tiles[i]->shut();
						shutters[i] = 0;
					}
				}
				roll(dice);
			} else {
				mvprintw(15, 11, "Invalid play. Please select tiles with sum %d", die0.val + die1.val);
			}

		} else if (ch == 'r') {
			for (Tile *t : tiles) t->_open();		
			for (int i = 0; i < 12; i++) shutters[i] = 0;
			roll(dice);
		}
		ch = getch();
	}

	end_display();
}
