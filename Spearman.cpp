#include "Spearman.h"

Spearman::Spearman(int x, int y) : Infantry(90, 10, 25, x, y) {}
std::unique_ptr<Unit> Spearman::clone() const { return std::make_unique<Spearman>(*this); }
std::string Spearman::getType() const { return "Spearman"; }