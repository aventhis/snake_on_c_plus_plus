#include "snake_game_controller.h"
#include <ncurses.h>

namespace s21 {

SnakeGameController::SnakeGameController(SnakeGameModel& model, SnakeGameView& view) 
: model_(model), view_(view) {}

UserAction_t SnakeGameController::getUserAction(int ch){
    switch(ch) {
        case 'q':
        case 'Q':
            return Terminate;
        case KEY_UP:
            return Up;
        case KEY_DOWN:
            return Down;
        case KEY_LEFT:
            return Left;
        case KEY_RIGHT:
            return Right;
        case ' ':
            return Action;
        case 'P':
        case 'p':
            return Pause;
         default:
            return Start;     
    }
}

void SnakeGameController::run() {
    initscr();             // Инициализация ncurses
    cbreak();              // ввод символов обрабатывается немедленно
    noecho();              // Отключение вывода вводимых символов
    curs_set(0);           // Скрытие курсора
    keypad(stdscr, TRUE);  // Включение обработки функциональных клавиш
    timeout(100);          // Установка таймаута для getch()

    while(true) {
        int ch = getch();
        UserAction_t action = getUserAction(ch);
        if(action == Terminate) {
            break;
        }

        if(model_.isGameOver()) {
            break;
        }
        // из view делаем отрисовку
        view_.drawField();
    }
     endwin();  // Завершение работы с ncurses
}

} // namespace s21