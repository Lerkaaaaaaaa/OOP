#include "GameField.h"
#include <stdexcept>

GameField::GameField(int w, int h, size_t maxU) : width(w), height(h), maxUnits(maxU) {
    grid.resize(width * height);
}

size_t GameField::toIndex(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height)
        throw std::out_of_range("Coordinates out of bounds");
    return y * width + x;
}

GameField::GameField(const GameField& other)
    : width(other.width), height(other.height), maxUnits(other.maxUnits) {
    grid.reserve(other.grid.size());
    for (const auto& unit : other.grid) {
        if (unit) grid.push_back(unit->clone());
        else grid.push_back(nullptr);
    }
}

GameField& GameField::operator=(const GameField& other) {
    if (this != &other) {
        GameField temp(other);
        std::swap(width, temp.width);
        std::swap(height, temp.height);
        std::swap(maxUnits, temp.maxUnits);
        std::swap(grid, temp.grid);
    }
    return *this;
}

void GameField::addUnit(std::unique_ptr<Unit> unit, int x, int y) {
    size_t index = toIndex(x, y);
    if (grid[index] != nullptr) throw std::runtime_error("Cell occupied");

    size_t currentCount = 0;
    for (const auto& u : grid) if (u) currentCount++;
    if (currentCount >= maxUnits) throw std::runtime_error("Max limit reached");

    unit->move(x, y);
    grid[index] = std::move(unit);
}

void GameField::removeUnit(int x, int y) {
    grid[toIndex(x, y)].reset();
}

Unit* GameField::getUnit(int x, int y) {
    return grid[toIndex(x, y)].get();
}

GameFieldIterator GameField::begin() { return GameFieldIterator(*this, 0); }
GameFieldIterator GameField::end() { return GameFieldIterator(*this, grid.size()); }