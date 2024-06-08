#ifndef SNAKE_GAME_CONTROLLER_H
#define SNAKE_GAME_CONTROLLER_H

#include "snake_game_model.h"

namespace s21 {

typedef enum {
    Start,
    Pause,
    Terminate,
    Left,
    Right,
    Up,
    Down,
    Action
} UserAction_t;

// Forward declaration
class SnakeGameModel;
class SnakeGameView;

// Сlass SnakeGameController - View+Model
class SnakeGameController {
public:
    explicit SnakeGameController(SnakeGameModel& model, SnakeGameView& view);
    void run(bool showWelcomeScreen);
    UserAction_t getUserAction(int ch);
private:
   SnakeGameModel& model_;
   SnakeGameView& view_;
}; // class SnakeGameController

} // namespace s21

#endif // SNAKE_GAME_CONTROLLER_H