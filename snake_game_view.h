#ifndef SNAKE_GAME_VIEW_H
#define SNAKE_GAME_VIEW_H

#include "snake_game_model.h"

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
    explicit SnakeGameView(SnakeGameModel& model) : model_(model) {};
    void drawField() const;
private:
   SnakeGameModel& model_;
}; // class SnakeGameView

} // namespace s21

#endif // SNAKE_GAME_VIEW_H