#include "HorseArcher.h"

HorseArcher::HorseArcher(int x, int y) : Cavalry(110, 15, 30, x, y) {}
std::unique_ptr<Unit> HorseArcher::clone() const { return std::make_unique<HorseArcher>(*this); }
std::string HorseArcher::getType() const { return "HorseArcher"; }