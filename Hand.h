#include <iostream>
#include <vector>
#include <istream>
#include "Card.h"
#include "CardFactory.h" 

class Hand {
private:
    std::vector<Card*> cards;

public:
    Hand& operator+=(Card* card) { // Fonction permettant d'ajouter une carte au dos de la main
        cards.push_back(card);
        return *this;
    }

    Card* play() { // Fonction permettant de jouer la premiere carte de la main
        if (cards.empty()) {
            return nullptr; 
        }

        Card* topCard = cards.front();
        cards.erase(cards.begin());
        return topCard;
    }

    
    Card* top() const { /// Fonction permettant d'obtenir la carte premiere sans la retirer
        return cards.empty() ? nullptr : cards.front();
    }

    Card* operator[](int index) { // Fonction permettant de jouer une carte à un index spécifique
        if (index < 0 || index >= cards.size()) {
            return nullptr; 
        }

        Card* selectedCard = cards[index];
        cards.erase(cards.begin() + index);
        return selectedCard;
    }

    
    friend std::ostream& operator<<(std::ostream& out, const Hand& hand) { // Fonction friend pour imprimer Hand sur un std::ostream
        for (const auto& card : hand.cards) {
            out << *card << " ";
        }
        return out;
    }

    
    Hand(std::istream& is, const CardFactory* factory) { // Constructor 
    }

    
    ~Hand() { // Destructor 
        for (auto card : cards) {
            delete card;
        }
    }
};
