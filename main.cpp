#include <iostream>
#include <memory>
#include "GameField.h"
#include "ConcreteUnitFactory.h"

int main() {
    try {
        std::cout << " Stage 1: Setup \n";
        GameField field(10, 10, 5);

        ConcreteUnitFactory factory;

        std::cout << "\n Stage 2: Creating units via Factory Method \n";
        
        field.addUnit(factory.createUnit("Swordsman", 0, 0), 0, 0);
        field.addUnit(factory.createUnit("Spearman", 0, 0), 1, 0);
        field.addUnit(factory.createUnit("LightArcher", 0, 0), 2, 0);
        field.addUnit(factory.createUnit("Cataphract", 0, 0), 5, 5);

        std::cout << "\n Stage 3: Iteration (Range-for) \n";
        for (Unit* u : field) {
            std::cout << u->getType() << " at (" << u->getX() << "," << u->getY() << ") HP: " << u->getHealth() << "\n";
        }
        std::cout << "\n Stage 4: Deep Copy test \n";
        GameField copiedField = field;
        copiedField.removeUnit(0, 0);

        std::cout << "Original units count: ";
        int count = 0; for (Unit* u : field) count++;
        std::cout << count << "\n";

        std::cout << "Copied units count: ";
        count = 0; for (Unit* u : copiedField) count++;
        std::cout << count << "\n";

        std::cout << "\n Stage 5: Move semantics test \n";
        GameField movedField = std::move(copiedField);
        std::cout << "Moved units count: ";
        count = 0; for (Unit* u : movedField) count++;
        std::cout << count << "\n";

        std::cout << "\n Stage 6: Error handling test \n";
        try {
            field.addUnit(factory.createUnit("Swordsman", 0, 0), 0, 0); 
        }
        catch (const std::exception& e) {
            std::cout << "Caught expected error: " << e.what() << "\n";
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Fatal: " << e.what() << "\n";
    }
    return 0;
}