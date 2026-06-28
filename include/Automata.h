// Copyright 2026 Astafeva Anastasiia

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK, COLLECT };

class Automata {
 private:
  int cash;
  int selected;
  std::vector<std::string> menu;
  std::vector<int> prices;
  STATES state;

 public:
  Automata();
  void on();
  void off();
  void coin();
  int getCash();
  std::vector<std::string> getMenu();
  STATES getState();
  void choice(std::string item);
  void check();
  void cancel();
  void cook();
  void finish();
};

#endif  // INCLUDE_AUTOMATA_H_
