// Copyright 2026 Astafeva Anastasiia

#include "Automata.h"
#include <string>
#include <vector>
#include <iostream>

Automata::Automata() {
    cash = 0;
    selected = -1;
    menu = {"Coffee", "Tea", "Cocoa", "Water"};
    prices = {3, 2, 2, 1};
    state = OFF;
}

void Automata::on() {
    if (state == OFF) state = WAIT;
}

void Automata::off() {
    if (state == WAIT) state = OFF;
}

void Automata::coin() {
    if (state == WAIT) state = ACCEPT;
    if (state == ACCEPT) cash++;
}

int Automata::getCash() {
    return cash;
}

void Automata::choice(std::string item) {
    if (state != ACCEPT) return;
    auto it = std::find(menu.begin(), menu.end(), item);
    if (it == menu.end()) return;
    selected = std::distance(menu.begin(), it);
    state = CHECK;
}

void Automata::check() {
    if (state != CHECK) return;
    if (cash >= prices[selected]) {
        cash -= prices[selected];
        state = COOK;
    } else {
        state = ACCEPT;
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
    }
}

void Automata::cook() {
    if (state == COOK) state = COLLECT;
}

void Automata::finish() {
    if (state == COLLECT) state = WAIT;
}

std::vector<std::string> Automata::getMenu() {
    std::vector<std::string> mp;
    for (int i = 0; i < static_cast<int>(menu.size()); i++) {
        mp.push_back(menu[i] + " - " + std::to_string(prices[i]));
    }
    return mp;
}

STATES Automata::getState() {
    return state;
}
