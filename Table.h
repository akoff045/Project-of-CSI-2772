//Audrey Koffi-300263639
//Tamer Verir-300177023

#include <iostream>
#include <string>
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include "CardFactory.h"
#include "Hand.h"

class Table {
private:
    Player player1;
    Player player2;
    Deck deck;
    DiscardPile discardPile;
    TradeArea tradeArea;
    Hand hand;

public:
    Table(std::istream& p1, std::istream& p2, std::istream& d, const CardFactory* cf)
        : player1(p1, cf),
          player2(p1, cf),
          deck(d, cf),
          discardPile(),
          tradeArea(d, cf) {}

    bool Table::win(std::string& winningPlayer) {
        if (deck.empty()) {
            int coinsPlayer1 = player1.getNumCoins();
            int coinsPlayer2 = player2.getNumCoins();

            if (coinsPlayer1 > coinsPlayer2) {
                winningPlayer = player1.getName();
                return true;
            } else{
                winningPlayer = player2.getName();
                return true;
            }
        }
        return false;
    }


    void printHand(bool bl) {
        if (bl == true) {
            Card* topCard = hand.top();
        }else{
            std::cout << hand;
        }

    }

    friend std::ostream& operator<<(std::ostream& os, const Table& table) {
        os << "Player 1: " << table.player1 << std::endl;
        os << "Player 2: " << table.player2 << std::endl;
        os << "Discard Pile: " << table.discardPile << std::endl;
        os << "Trade Area: " << table.tradeArea << std::endl;
        return os;
    }
};
