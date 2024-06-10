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

typedef struct {
    std::vector<std::vector<int>> field; // Игровое поле размером 10x20
    int score;      // Текущий счет
    int high_score; // Рекорд
    int level;      // Уровень сложности игры
    int speed;      // Скорость игры
    int pause;      // Состояние паузы (1 - игра на паузе, 0 - игра активна)
} GameInfo_t;


// Сlass SnakeGameModel - logic for Snake
class SnakeGameModel {
public:
    //Constructor to initialize the game grid
    SnakeGameModel(int wigth, int height);
    std::vector< std::vector <int> > getField () const;
    bool isGameOver();
    bool isGameWin();
    void generateApple();
    void setDirection(Direction dir);
    void moveSnake();
    void restartGame();
    

private:
    GameInfo_t gameInfo_;
    int width_;
    int height_;
    std::vector< std::vector <int> > field_;
    std::vector<std::pair<int,int>> snake_;
    bool gameOver_;
    bool gameWin_;
    Direction direction_;
}; // class SnakeGameModel

} // namespace s21

#endif // SNAKE_GAME_MODEL_H