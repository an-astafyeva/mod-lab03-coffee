// Copyright 2026 Astafeva Anastasiia

#include "Automata.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> states = {"OFF", "WAIT", "ACCEPT",
                                       "CHECK", "COOK", "COLLECT"};
    Automata cof;
    std::cout << "State: " << states[cof.getState()] << std::endl;

    std::cout << "Switching on" << std::endl;
    cof.on();
    std::cout << "State: " << states[cof.getState()] << std::endl;

    std::cout << "Menu:" << std::endl;
    for (std::string s : cof.getMenu())
        std::cout << "  " << s << std::endl;

    std::cout << "Adding 2 coins" << std::endl;
    cof.coin();
    cof.coin();
    std::cout << "State: " << states[cof.getState()] << std::endl;

    std::cout << "Choosing Coffee (costs 3, have 2)" << std::endl;
    cof.choice("Coffee");
    cof.check();
    std::cout << "State: " << states[cof.getState()] << std::endl;

    std::cout << "Adding 1 more coin" << std::endl;
    cof.coin();
    std::cout << "State: " << states[cof.getState()] << std::endl;

    std::cout << "Choosing Coffee again (costs 3, have 3)" << std::endl;
    cof.choice("Coffee");
    cof.check();
    std::cout << "State: " << states[cof.getState()] << std::endl;

    std::cout << "Cooking..." << std::endl;
    cof.cook();
    std::cout << "State: " << states[cof.getState()] << std::endl;

    std::cout << "Collecting drink" << std::endl;
    cof.finish();
    std::cout << "State: " << states[cof.getState()] << std::endl;

    std::cout << "Turning off" << std::endl;
    cof.off();
    std::cout << "State: " << states[cof.getState()] << std::endl;

    return 0;
}
