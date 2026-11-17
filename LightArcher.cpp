#include "LightArcher.h"

LightArcher::LightArcher(int x, int y) : Archer(70, 5, 30, x, y) {}
std::unique_ptr<Unit> LightArcher::clone() const { return std::make_unique<LightArcher>(*this); }
std::string LightArcher::getType() const { return "LightArcher"; }