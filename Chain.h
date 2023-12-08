//Audrey Koffi-300263639
//Tamer Verir-300177023

#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include "Card.h"  

class Chain_Base {
public:
    virtual int sell() const = 0;
    virtual ~Chain_Base() = default;
};

template <class T>
class Chain : public Chain_Base {
    std::vector<std::shared_ptr<T>> cards;

public:
    Chain() = default;

    Chain(std::istream& is, const CardFactory* factory) {
         while (is) {
            std::string cardName;
            is >> cardName; // Lit le nom de la carte depuis le flux

            if (cardName.empty()) {
                break; // S'arrête si il n'y a aucune carte à lire
            }

            Card* newCard = factory->getCard(cardName); // Utilise le CardFactory pour créer une carte en fonction du nom lu depuis le flux

            if (newCard != nullptr) {
                *this += newCard; // Ajoute la carte à la chaîne 
            }
        }
    }

    Chain& operator+=(Card* card) {// Ajoute une carte à la fin de la chaîne
        
        T* specificCard = dynamic_cast<T*>(card);
        if (specificCard) {
            cards.push_back(std::shared_ptr<T>(specificCard));
        } else {
            throw std::runtime_error("IllegalType exception");
        }
        return *this;
    }

    int sell() const override {
        return cards.size() > 0 ? cards.front()->getCardsPerCoin(cards.size()) : 0;
    }

    friend std::ostream& operator<<(std::ostream& out, const Chain<T>& chain) {
        for (const auto& card : chain.cards) {
            out << card->getName() << " ";
        }
        return out;
    }
};


