#pragma once
#include <vector>
#include <memory>
#include "Unit.h"

class GameField;

class GameFieldIterator {
private:
    GameField& field;
    size_t currentIndex;
    void skipEmpty();

public:
    GameFieldIterator(GameField& f, size_t index);
    Unit* operator*() const;
    GameFieldIterator& operator++();
    bool operator!=(const GameFieldIterator& other) const;
};
