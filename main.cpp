#include <iostream>
#include <string>
using namespace std;
// Common super class interface
class Beverage {
public:
    string description = "unknown beverage";
    virtual string getDescription() {
        return description;
    }
    virtual double cost() = 0;
    virtual ~Beverage() = default;
};

// Concrete coffee classes
class HouseBlend : public Beverage {
public:
    HouseBlend() {
        description = "House Blend Coffee";
    }

    double cost()override {
        return 1.99;
    }
};

class DarkRoast : public Beverage {
public:
    DarkRoast() {
        description = "Dark Roast Coffee";
    }

    double cost() override {
        return 2.49;
    }
};

class Decaf : public Beverage {
public:
    Decaf() {
        description = "Decaf Coffee";
    }

    double cost() override {
        return 1.79;
    }
};

class Espresso : public Beverage {
public:
    Espresso() {
        description = "Espresso Coffee";
    }

    double cost() override {
        return 1.99;
    }
};

class Cordiments : public Beverage {
public:
    virtual string getDescription() = 0;
};
// Decorators or condiments
class Milk : public Beverage {
private:
    Beverage* beverage;

public:
    Milk(Beverage* beverage) : beverage(beverage) {}

    string getDescription() override {
        return beverage->getDescription() + ", Milk";
    }

    double cost() override {
        return beverage->cost() + 0.10;
    }

    ~Milk() override {
        delete beverage;
    }
};

class Whip : public Beverage {
private:
    Beverage* beverage;

public:
    Whip(Beverage* beverage) : beverage(beverage) {}

    string getDescription() override {
        return beverage->getDescription() + ", Whip";
    }

    double cost() override {
        return beverage->cost() + 0.15;
    }

    ~Whip() override {
        delete beverage;
    }
};

class Mocha : public Beverage {
private:
    Beverage* beverage;

public:
    Mocha(Beverage* beverage) : beverage(beverage) {}

    string getDescription() override {
        return beverage->getDescription() + ", Mocha";
    }

    double cost() override {
        return beverage->cost() + 0.20;
    }

    ~Mocha() override {
        delete beverage;
    }
};

class Soy : public Beverage {
private:
    Beverage* beverage;

public:
    Soy(Beverage* beverage) : beverage(beverage) {}

    string getDescription() override {
        return beverage->getDescription() + ", Soy";
    }

    double cost() override {
        return beverage->cost() + 0.15;
    }

    ~Soy() override {
        delete beverage;
    }
};

int main() {
    // Example usage
    Beverage* beverage = new Espresso();
    std::cout << "Description: " << beverage->getDescription() << "\n";
    std::cout << "Cost: $" << beverage->cost() << "\n";

    // Adding decorators
    beverage = new Mocha(beverage);
    beverage = new Mocha(beverage);
    beverage = new Whip(beverage);

    std::cout << "Description: " << beverage->getDescription() << "\n";
    std::cout << "Cost: $" << beverage->cost() << "\n";

    delete beverage;  // Clean up memory

    return 0;
}
