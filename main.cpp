#include "snake_game_model.h"
#include "snake_game_view.h"
#include "snake_game_controller.h"
#include <ncurses.h>

int main() {
    
    s21::SnakeGameModel model(20,20);
    s21::SnakeGameView view(model);
    s21::SnakeGameController controller (model, view);
    controller.run(true);
    
    return 0;
}