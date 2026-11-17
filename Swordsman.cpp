#include "Swordsman.h"

Swordsman::Swordsman(int x, int y) : Infantry(100, 15, 20, x, y) {}
std::unique_ptr<Unit> Swordsman::clone() const { return std::make_unique<Swordsman>(*this); }
std::string Swordsman::getType() const { return "Swordsman"; }