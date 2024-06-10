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
    void init_gui();
    UserAction_t getUserAction(int ch);
    void userInput(UserAction_t action, bool hold);
private:
   SnakeGameModel& model_;
   SnakeGameView& view_;
}; // class SnakeGameController

} // namespace s21

#endif // SNAKE_GAME_CONTROLLER_H