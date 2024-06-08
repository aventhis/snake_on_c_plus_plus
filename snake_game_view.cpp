#include "snake_game_view.h"
#include <ncurses.h>

namespace s21 {

SnakeGameView::SnakeGameView(SnakeGameModel& model) : model_(model) {}

void SnakeGameView::showWelcomeScreen() {
    clear();  // Очищаем экран
    int height = 22; 
    int width = 22;  
    WINDOW *start_win = newwin(height, width, 0, 0);
    box(start_win, 0, 0);  // Добавление рамки

    // Вывод текста
    const char* title1 = "Welcome to";
    const char* title2 = "SNAKE GAME";
    const char* title3 = "Press Enter to start";
    const char* title4 = "Press 'Q' to quit";
    mvwprintw(start_win, height / 2 - 5, (width - strlen(title1)) / 2, "%s", title1);
    mvwprintw(start_win, height / 2 - 3, (width - strlen(title2)) / 2, "%s", title2);
    mvwprintw(start_win, height / 2 + 1, (width - strlen(title3)) / 2, "%s", title3);
    mvwprintw(start_win, height / 2 + 2, (width - strlen(title4)) / 2, "%s", title4);

    keypad(start_win, TRUE);  // Включение обработки функциональных клавиш в окне
    int ch;
    bool continueLoop = true;
    while (continueLoop) {
        ch = wgetch(start_win);
        switch (ch) {
            case '\n':  // Enter
            case KEY_ENTER:
                continueLoop = false;  // Выход из цикла
                break;
            case 'q':
            case 'Q':
                endwin();  // Завершаем ncurses
                exit(0);   // Выход из программы
                break;
        }
    }

    delwin(start_win);  // Удаление окна
}

int SnakeGameView::showResultScreen(bool gameOver, bool gameWin) {
    clear();  // Очищаем экран
    int height = 22; 
    int width = 22;  
    WINDOW *start_win = newwin(height, width, 0, 0);
    box(start_win, 0, 0);  // Добавление рамки

    const char *title1 = "", *title2 = "Press Enter", *title3 = "to RESTART", *title4 = "Press 'Q' to quit";
    if (gameOver) {
        title1 = "GAME OVER";
    } else if (gameWin) {
        title1 = "GAME WIN";
    }

    mvwprintw(start_win, height / 2 - 5, (width - strlen(title1)) / 2, "%s", title1);
    mvwprintw(start_win, height / 2, (width - strlen(title3)) / 2, "%s", title2);
    mvwprintw(start_win, height / 2 + 1, (width - strlen(title3)) / 2, "%s", title3);
    mvwprintw(start_win, height / 2 + 2, (width - strlen(title4)) / 2, "%s", title4);
    

    keypad(start_win, TRUE);  // Включение обработки функциональных клавиш в окне
    int ch = 0;
    while (true) {
        ch = wgetch(start_win);
        if (ch == '\n' || ch == KEY_ENTER || ch == 'q' || ch == 'Q') {
            break;
        }
    }

    delwin(start_win);  // Удаление окна
    endwin();  // Завершаем ncurses, если нужно выйти
    if (ch == 'q' || ch == 'Q') {
        exit(0);  // Выход из программы
    }
    return ch;
}


void SnakeGameView::drawField() const {
    const auto& field = model_.getField();
    clear();  // Очистка экрана
    // bool is_head = true;
    for(size_t y = 0; y < field.size(); y++) {
         for(size_t x = 0; x < field[y].size(); x++) {
            //Перемещает курсор на позицию (y, x) на экране.
            move(y,x);
            if(field[y][x] == Field)
                addch('.'); 
            else if(field[y][x] == SnakeHead) 
                addch('"');
            else if(field[y][x] == SnakeBody)
                addch('#'); 
            else if(field[y][x] == Apple)
                addch('0'); 
            else if (field[y][x] == Border) 
                addch('3'); 
         }
         std::cout << std::endl;
    }
    refresh();  // Обновление экрана
}

} // namespace s21
