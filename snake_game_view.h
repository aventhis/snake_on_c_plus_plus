#ifndef SNAKE_GAME_VIEW_H
#define SNAKE_GAME_VIEW_H

#include "snake_game_model.h"
#include <cstring>

namespace s21 {

typedef enum {
    Field,
    SnakeHead,
    SnakeBody,
    Apple,
    Border,
} FieldView;

// Forward declaration
class SnakeGameModel;

// Сlass SnakeGameView - view for Snake in terminal
class SnakeGameView {
public:
    explicit SnakeGameView(SnakeGameModel& model);
    void showWelcomeScreen();
    int showResultScreen(bool gameOver, bool gameWin);
    void drawField() const;
    void initializeColors();
private:
   SnakeGameModel& model_;
}; // class SnakeGameView

} // namespace s21

#endif // SNAKE_GAME_VIEW_H