#include "snake_game_model.h"
#include <cstdlib>  // Для функции rand()
#include <ctime>    // Для функции time()

namespace s21 {

SnakeGameModel::SnakeGameModel(int width, int height)
    : width_(width + 2), height_(height + 2), field_(height + 2, std::vector<int>(width + 2, 0)), gameOver_(false), direction_(Direction::Left)  {
    // инициализация генеротора случайных чисел
    srand(time(nullptr));
    
    // Установка начального положения змейки: голова и три сегмента хвоста
    int snake_y = height / 2;
    int snake_x = width / 2;

    // Голова
    snake_.push_back({snake_y, snake_x});
    field_[snake_y][snake_x] = SnakeHead;

    // Хвостовые сегменты
    for (int i = 1; i <= 3; ++i) {
        snake_.push_back({snake_y, snake_x - i});
        field_[snake_y][snake_x - i] = SnakeBody;
    }

    // Установка начального положения яблока
    int apple_x = 5 + 1; 
    int apple_y = 5 + 1;
    field_[apple_y][apple_x] = Apple;

    // Установка стенок
    for (int x = 0; x < width_; ++x) {
        field_[0][x] = Border;
        field_[height_ - 1][x] = Border;
    }
    for (int y = 0; y < height_; ++y) {
        field_[y][0] = Border;
        field_[y][width_ - 1] = Border;
    }
}

std::vector<std::vector<int>> SnakeGameModel::getField() const {
    return field_;
}

bool SnakeGameModel::isGameOver() {
    return gameOver_;
}

void SnakeGameModel::setDirection(Direction dir) {
    if(dir == Direction::Up || dir == Direction::Down || dir == Direction::Left || dir == Direction::Right) {
        direction_ = dir;
    }
}

void SnakeGameModel::moveSnake() {
    if(gameOver_) return;

    std::pair<int,int> new_head = snake_.front();
    switch (direction_) {
        case Direction::Up:
            new_head.first--;
            break;
        case Direction::Down:
            new_head.first++;
            break;
        case Direction::Left:
            new_head.second--;
            break;
        case Direction::Right:
            new_head.second++;
            break;
    }

    //обработка столкновения
    if(new_head.second < 1 || new_head.first < 1||new_head.second >= width_ -1 || new_head.first >= height_ -1)
        gameOver_ = true;
    
     // Обновление головы
    field_[snake_.front().first][snake_.front().second] = SnakeBody;
    snake_.insert(snake_.begin(), new_head);
    
    // змейка съедает яблоко
    if (field_[new_head.first][new_head.second] == Apple) {
        // перед генерацией нового яблока проверить на наличие пустового места
        // если не осталось то win
        generateApple();
    } else {
        // Удаление хвоста
        auto tail = snake_.back();
        field_[tail.first][tail.second] = 0;
        snake_.pop_back();
    }
    field_[new_head.first][new_head.second] = SnakeHead;
}

void SnakeGameModel::generateApple() {
    int x, y;
    do {
        x = rand() % width_;
        y = rand() % height_;
    } while (field_[y][x] != Field);  // Проверяем, что выбранная ячейка пуста

    field_[y][x] = Apple;
}

}  // namespace s21
