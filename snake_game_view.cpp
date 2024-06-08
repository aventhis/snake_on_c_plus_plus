#include "snake_game_view.h"
#include <ncurses.h>

namespace s21 {

// SnakeGameView::SnakeGameView(SnakeGameModel& model) 


void SnakeGameView::drawField() const {
    const auto& field = model_.getField();
    clear();  // Очистка экрана
    // bool is_head = true;
    for(size_t y = 0; y < field.size(); y++) {
         for(size_t x = 0; x < field[y].size(); x++) {
            //Перемещает курсор на позицию (y, x) на экране.
            move(y,x);
            if(field[y][x] == Field)
                addch('.'); 
            else if(field[y][x] == SnakeHead) 
                addch('"');
            else if(field[y][x] == SnakeBody)
                addch('#'); 
            else if(field[y][x] == Apple)
                addch('0'); 
            else if (field[y][x] == Border) 
                addch('3'); 
         }
         std::cout << std::endl;
    }
    refresh();  // Обновление экрана
}

} // namespace s21
