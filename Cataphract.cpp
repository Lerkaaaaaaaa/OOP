#include "Cataphract.h"

Cataphract::Cataphract(int x, int y) : Cavalry(150, 30, 40, x, y) {}
std::unique_ptr<Unit> Cataphract::clone() const { return std::make_unique<Cataphract>(*this); }
std::string Cataphract::getType() const { return "Cataphract"; }