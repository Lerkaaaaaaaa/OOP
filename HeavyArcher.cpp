#include "HeavyArcher.h"

HeavyArcher::HeavyArcher(int x, int y) : Archer(85, 10, 35, x, y) {}
std::unique_ptr<Unit> HeavyArcher::clone() const { return std::make_unique<HeavyArcher>(*this); }
std::string HeavyArcher::getType() const { return "HeavyArcher"; }