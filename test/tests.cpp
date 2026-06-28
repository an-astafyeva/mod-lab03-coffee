// Copyright 2026 Astafeva Anastasiia

#include "Automata.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(correct_transition, test1_initial_off) {
    Automata a;
    EXPECT_EQ(OFF, a.getState());
}

TEST(correct_transition, test2_on) {
    Automata a;
    a.on();
    EXPECT_EQ(WAIT, a.getState());
}

TEST(correct_transition, test3_off) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(OFF, a.getState());
}

TEST(correct_transition, test4_coin_from_wait) {
    Automata a;
    a.on();
    a.coin();
    EXPECT_EQ(ACCEPT, a.getState());
}

TEST(correct_transition, test5_coin_from_accept) {
    Automata a;
    a.on();
    a.coin();
    a.coin();
    EXPECT_EQ(ACCEPT, a.getState());
}

TEST(correct_transition, test6_coin_from_off) {
    Automata a;
    a.coin();
    EXPECT_EQ(OFF, a.getState());
}

TEST(correct_transition, test7_choice) {
    Automata a;
    a.on();
    a.coin();
    a.choice("Tea");
    EXPECT_EQ(CHECK, a.getState());
}

TEST(correct_transition, test8_check_enough) {
    Automata a;
    a.on();
    a.coin();
    a.coin();
    a.choice("Tea");
    a.check();
    EXPECT_EQ(COOK, a.getState());
}

TEST(correct_transition, test9_check_not_enough) {
    Automata a;
    a.on();
    a.coin();
    a.choice("Tea");
    a.check();
    EXPECT_EQ(ACCEPT, a.getState());
}

TEST(correct_transition, test10_cook) {
    Automata a;
    a.on();
    a.coin();
    a.coin();
    a.choice("Tea");
    a.check();
    a.cook();
    EXPECT_EQ(COLLECT, a.getState());
}

TEST(correct_transition, test11_finish) {
    Automata a;
    a.on();
    a.coin();
    a.coin();
    a.choice("Tea");
    a.check();
    a.cook();
    a.finish();
    EXPECT_EQ(WAIT, a.getState());
}

TEST(correct_transition, test12_cancel_from_accept) {
    Automata a;
    a.on();
    a.coin();
    a.cancel();
    EXPECT_EQ(WAIT, a.getState());
}

TEST(correct_transition, test13_cancel_from_check) {
    Automata a;
    a.on();
    a.coin();
    a.choice("Tea");
    a.cancel();
    EXPECT_EQ(WAIT, a.getState());
}

TEST(correct_transition, test14_cash_deducted) {
    Automata a;
    a.on();
    a.coin();
    a.coin();
    a.coin();
    a.choice("Coffee");
    a.check();
    EXPECT_EQ(0, a.getCash());
}

TEST(correct_transition, test15_unknown_item) {
    Automata a;
    a.on();
    a.coin();
    a.choice("Lemonade");
    EXPECT_EQ(ACCEPT, a.getState());
}
