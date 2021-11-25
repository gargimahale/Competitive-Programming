#include <bits/stdc++.h>
using namespace std;

struct Unit {
	string name;
	int32_t hp, damage, armor;
};

struct Item {
	string name;
	int32_t cost, damage, armor;
};

vector<Item> weapons = {
	Item{ "Dagger", 8, 4, 0 },
	Item{ "Shortsword", 10, 5, 0 },
	Item{ "Warhammer", 25, 6, 0 },
	Item{ "Longsword", 40, 7, 0 },
	Item{ "Greataxe", 74, 8, 0 },
};

vector<Item> armor = {
	Item{ "Leather", 13, 0, 1 },
	Item{ "Chainmail", 31, 0, 2 },
	Item{ "Splintmail", 53, 0, 3 },
	Item{ "Bandedmail", 75, 0, 4 },
	Item{ "Platemail", 102, 0, 5 },
};

vector<Item> rings = {
	Item{ "Damage +1", 25, 1, 0 },
	Item{ "Damage +2", 50, 2, 0 },
	Item{ "Damage +3", 100, 3, 0 },
	Item{ "Defense +1", 20, 0, 1 },
	Item{ "Defense +2", 40, 0, 2 },
	Item{ "Defense +3", 80, 0, 3 },
};

void P1(istream& input);
void P2(istream& input);
void equip(Unit& unit, const Item& item);
void unequip(Unit& unit, const Item& item);
bool playerWins(const Unit& player, const Unit& boss);
bool playerWinsSimulation(Unit& player, Unit& boss);

int main(void) {
    ifstream infile("input.txt");
    P1(infile);

    infile.clear();
    infile.seekg(0);

    P2(infile);
}

void P1(istream& input) {

    Unit player = { "player", 100, 0, 0 };
    Unit boss = { "boss", 0, 0, 0 };

    string stat;
    uint32_t value;
    while (input >> stat) {

        if (stat == "Hit") {
            input >> stat >> value;
            boss.hp = value;
        } else if (stat == "Damage:") {
            input >> value;
            boss.damage = value;
        } else if (stat == "Armor:") {
            input >> value;
            boss.armor = value;
        } else {
            cout << "Failed to read input: " << stat << endl;
            exit(1);
        }
    }

    int32_t result = numeric_limits<int32_t>::max();

    for (const auto& w : weapons) {

        Unit& p = player;
        const Unit& b = boss;

        int32_t cost = w.cost;
        equip(p, w);

        // Just weapon
        if (playerWins(p, b)) {
            result = min(result, cost);
        }

        for (const auto& a : armor) {
            
            cost += a.cost;
            equip(p, a);

            // Weapon + Armor
            if (playerWins(p, b)) {
                result = min(result, cost);
            }

            for (size_t i = 0; i < rings.size(); i++) {
                cost += rings[i].cost;
                equip(p, rings[i]);

                // Weapon + Armor + 1 ring
                if (playerWins(p, b)) {
                    result = min(result, cost);
                }

                for (size_t j = i+1; j < rings.size(); j++) {
                    cost += rings[j].cost;
                    equip(p, rings[j]);

                    // Weapon + Armor + 2 rings
                    if (playerWins(p, b)) {
                        result = min(result, cost);
                    }

                    cost -= rings[j].cost;
                    unequip(p, rings[j]);
                }

                cost -= rings[i].cost;
                unequip(p, rings[i]);
            }

            cost -= a.cost;
            unequip(p, a);
        }

        for (size_t i = 0; i < rings.size(); i++) {
            cost += rings[i].cost;
            equip(p, rings[i]);

            // Weapon + 1 ring
            if (playerWins(p, b)) {
                result = min(result, cost);
            }

            for (size_t j = i+1; j < rings.size(); j++) {
                cost += rings[j].cost;
                equip(p, rings[j]);

                // Weapon + 2 rings
                if (playerWins(p, b)) {
                    result = min(result, cost);
                }

                cost -= rings[j].cost;
                unequip(p, rings[j]);
            }

            cost -= rings[i].cost;
            unequip(p, rings[i]);
        }

        // Remove weapon here
        cost -= w.cost;
        unequip(p, w);
    }
    cout << "Least: " << result << endl;
}

void P2(istream& input) {
    Unit player = { "player", 100, 0, 0 };
    Unit boss = { "boss", 0, 0, 0 };

    string stat;
    uint32_t value;
    while (input >> stat) {

        if (stat == "Hit") {
            input >> stat >> value;
            boss.hp = value;
        } else if (stat == "Damage:") {
            input >> value;
            boss.damage = value;
        } else if (stat == "Armor:") {
            input >> value;
            boss.armor = value;
        } else {
            cout << "Failed to read input: " << stat << endl;
            exit(1);
        }
    }

    int32_t result = 0;
    for (const auto& w : weapons) {

        Unit& p = player;
        const Unit& b = boss;

        int32_t cost = w.cost;
        equip(p, w);

        // Just weapon
        if (!playerWins(p, b)) {
            result = max(result, cost);
        }

        for (const auto& a : armor) {
            
            cost += a.cost;
            equip(p, a);

            // Weapon + Armor
            if (!playerWins(p, b)) {
                result = max(result, cost);
            }

            for (size_t i = 0; i < rings.size(); i++) {
                cost += rings[i].cost;
                equip(p, rings[i]);

                // Weapon + Armor + 1 ring
                if (!playerWins(p, b)) {
                    result = max(result, cost);
                }

                for (size_t j = i+1; j < rings.size(); j++) {
                    cost += rings[j].cost;
                    equip(p, rings[j]);

                    // Weapon + Armor + 2 rings
                    if (!playerWins(p, b)) {
                        result = max(result, cost);
                    }

                    cost -= rings[j].cost;
                    unequip(p, rings[j]);
                }

                cost -= rings[i].cost;
                unequip(p, rings[i]);
            }

            cost -= a.cost;
            unequip(p, a);
        }

        for (size_t i = 0; i < rings.size(); i++) {
            cost += rings[i].cost;
            equip(p, rings[i]);

            // Weapon + 1 ring
            if (!playerWins(p, b)) {
                result = max(result, cost);
            }

            for (size_t j = i+1; j < rings.size(); j++) {
                cost += rings[j].cost;
                equip(p, rings[j]);

                // Weapon + 2 rings
                if (!playerWins(p, b)) {
                    result = max(result, cost);
                }

                cost -= rings[j].cost;
                unequip(p, rings[j]);
            }

            cost -= rings[i].cost;
            unequip(p, rings[i]);
        }

        // Remove weapon here
        cost -= w.cost;
        unequip(p, w);
    }
    cout << "Most: " << result << endl;
}

void equip(Unit& unit, const Item& item) {
    unit.damage += item.damage;
    unit.armor += item.armor;
}

void unequip(Unit& unit, const Item& item) {
    unit.damage -= item.damage;
    unit.armor -= item.armor;
}

bool playerWins(const Unit& player, const Unit& boss) {
    int32_t pturns = ceil(1.0 * boss.hp / max(1, player.damage - boss.armor));
    int32_t bturns = ceil(1.0 * player.hp / max(1, boss.damage - player.armor));
    return (pturns <= bturns);
}

bool playerWinsSimulation(Unit& player, Unit& boss) {
    Unit units[] = { player, boss };

    uint8_t active = 0;

    while (true) {
        auto attacker = &units[active];
        auto victim = &units[1-active];

        int32_t dealt = max(1, attacker->damage - victim->armor);
        victim->hp = max(0, victim->hp - dealt);

        cout << "The " << attacker->name << " deals " << dealt << " damage; the "
                  << victim->name << " goes down to " << victim->hp << " hit points->" << endl;

        if (victim->hp <= 0) {
            break;
        }
        active = 1 - active;
    }

    return units[1].hp <= 0;
}