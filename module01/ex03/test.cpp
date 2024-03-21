#include <iostream>
#include <string>

class Weapon {
private:
    std::string type;

public:
    Weapon(const std::string& type) : type(type) {}

    const std::string& getType() const {
        return type;
    }

    void setType(const std::string& newType) {
        type = newType;
    }
};

class HumanA {
private:
    std::string name;
    Weapon& weapon;

public:
    HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {}

    void attack() const {
        std::cout << name << " attacks with his " << weapon.getType() << std::endl;
    }
};

class HumanB {
private:
    std::string name;
    Weapon* weapon;

public:
    HumanB(const std::string& name) : name(name), weapon(nullptr) {}

    void setWeapon(Weapon& newWeapon) {
        weapon = &newWeapon;
    }

    void attack() const {
        if (weapon) {
            std::cout << name << " attacks with his " << weapon->getType() << std::endl;
        } else {
            std::cout << name << " has no weapon to attack with." << std::endl;
        }
    }
};

int main() {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();

    Weapon club2 = Weapon("crude spiked club");
    HumanB jim("Jim");
	jim.attack();
    jim.setWeapon(club2);
    jim.attack();
    club2.setType("some other type of club");
    jim.attack();
}
