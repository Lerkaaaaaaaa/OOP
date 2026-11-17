#include "GameFieldIterator.h"
#include "GameField.h"

GameFieldIterator::GameFieldIterator(GameField& f, size_t index) : field(f), currentIndex(index) {
    skipEmpty();
}
void GameFieldIterator::skipEmpty() {
    while (currentIndex < field.getGrid().size() && !field.getGrid()[currentIndex]) {
        ++currentIndex;
    }
}
Unit* GameFieldIterator::operator*() const {
    return field.getGrid()[currentIndex].get();
}
GameFieldIterator& GameFieldIterator::operator++() {
    ++currentIndex;
    skipEmpty();
    return *this;
}
bool GameFieldIterator::operator!=(const GameFieldIterator& other) const {
    return currentIndex != other.currentIndex;
}