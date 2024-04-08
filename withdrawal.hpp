#include <iostream>
#include <string>
#pragma once


class Card {
    public:
        virtual int max_withdrawal() const = 0;
        virtual int max_credit() const = 0;
        virtual ~Card() {}

};

class GoldCard : public Card {
    public:
        int max_withdrawal() const override { return 5000;};
        int max_credit() const override{ return 10000;};

};

class PlatiniumCard : public Card {
    public:
        int max_withdrawal() const override { return 2500;};
        int max_credit() const override{return 5000;};
};

class BlackCard : public Card {
    public:
        int max_withdrawal() const override {return 1000;};
        int max_credit() const override {return 2000;};
};



