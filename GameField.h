#pragma once
#include <vector>
#include <memory>
#include "Unit.h"
#include "GameFieldIterator.h"

class GameField {
private:
    int width;
    int height;
    size_t maxUnits;
    std::vector<std::unique_ptr<Unit>> grid;

    size_t toIndex(int x, int y) const;

public:
    GameField(int w, int h, size_t maxU);

    GameField(const GameField& other);
    GameField& operator=(const GameField& other);
    GameField(GameField&&) noexcept = default;
    GameField& operator=(GameField&&) noexcept = default;
    ~GameField() = default;

    void addUnit(std::unique_ptr<Unit> unit, int x, int y);
    void removeUnit(int x, int y);
    Unit* getUnit(int x, int y);

    const std::vector<std::unique_ptr<Unit>>& getGrid() const { return grid; }

    GameFieldIterator begin();
    GameFieldIterator end();
};
