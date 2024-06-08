#ifndef SNAKE_GAME_MODEL_H
#define SNAKE_GAME_MODEL_H

#include <vector>
#include <iostream>
#include "snake_game_view.h"

namespace s21 {
    
enum class Direction {
    Up,
    Down,
    Left,
    Right
};
// Сlass SnakeGameModel - logic for Snake
class SnakeGameModel {
public:
    //Constructor to initialize the game grid
    SnakeGameModel(int wigth, int height);
    std::vector< std::vector <int> > getField () const;
    bool isGameOver();
    void generateApple();
    void setDirection(Direction dir);
    void moveSnake();
    

private:
    int width_;
    int height_;
    std::vector< std::vector <int> > field_;
    std::vector<std::pair<int,int>> snake_;
    bool gameOver_;
    Direction direction_;
}; // class SnakeGameModel

} // namespace s21

#endif // SNAKE_GAME_MODEL_H