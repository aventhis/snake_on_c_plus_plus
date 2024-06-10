#include "snake_game_controller.h"
#include <ncurses.h>

namespace s21 {

SnakeGameController::SnakeGameController(SnakeGameModel& model, SnakeGameView& view) 
: model_(model), view_(view) {}



void SnakeGameController::run(bool showWelcomeScreen = true) {
    init_gui();

    if(showWelcomeScreen)
        view_.showWelcomeScreen();
    
    while(true) {
        int ch = getch();
        UserAction_t action = getUserAction(ch);
    
        if(action == Terminate) {
            break;
        } 

        userInput(action, false);
        model_.moveSnake();
        
        if(model_.isGameOver() || model_.isGameWin()) {
            int Restart= view_.showResultScreen(model_.isGameOver(), model_.isGameWin());
            if(Restart == '\n' || Restart == KEY_ENTER) {
                model_.restartGame();
                run(false);  // Запуск игры
            } else  
                break;
        }
        
        // из view делаем отрисовку
        view_.drawField();
    }
     endwin();  // Завершение работы с ncurses
}

void SnakeGameController::init_gui(){
    initscr();             // Инициализация ncurses
    cbreak();              // ввод символов обрабатывается немедленно
    noecho();              // Отключение вывода вводимых символов
    curs_set(0);           // Скрытие курсора
    keypad(stdscr, TRUE);  // Включение обработки функциональных клавиш
    timeout(100);          // Установка таймаута для getch()
    view_.initializeColors();
}

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

void SnakeGameController::userInput(UserAction_t action, bool hold) {
    switch(action) {
            case Up:
                if (!hold)
                model_.setDirection(Direction::Up);
                break;
            case Down:
                if (!hold)
                model_.setDirection(Direction::Down);
                break;
            case Left:
                if (!hold)
                model_.setDirection(Direction::Left);
                break;
            case Right:
                if (!hold)
                model_.setDirection(Direction::Right);
                break;
            case Action:
                break;
            default:
                break;
        }
}

} // namespace s21