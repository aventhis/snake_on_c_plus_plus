#include "snake_game_model.h"

namespace s21 {

SnakeGameModel::SnakeGameModel(int width, int height)
    : width_(width + 2), height_(height + 2), field_(height + 2, std::vector<int>(width + 2, 0)), gameOver_(false) {
    // Установка начального положения змейки: голова и три сегмента хвоста
    int snake_y = height / 2 + 1;
    int snake_x = width / 2 + 1;

    // Голова
    snake_.push_back({snake_y, snake_x});
    field_[snake_y][snake_x] = 1;

    // Хвостовые сегменты
    for (int i = 1; i <= 3; ++i) {
        snake_.push_back({snake_y, snake_x - i});
        field_[snake_y][snake_x - i] = 1;
    }

    // Установка начального положения яблока
    int apple_x = 5 + 1; 
    int apple_y = 5 + 1;
    field_[apple_y][apple_x] = 2;

    // Установка стенок
    for (int x = 0; x < width_; ++x) {
        field_[0][x] = 3;
        field_[height_ - 1][x] = 3;
    }
    for (int y = 0; y < height_; ++y) {
        field_[y][0] = 3;
        field_[y][width_ - 1] = 3;
    }
}

std::vector<std::vector<int>> SnakeGameModel::getField() const {
    return field_;
}

bool SnakeGameModel::isGameOver() {
    return gameOver_;
}

}  // namespace s21
