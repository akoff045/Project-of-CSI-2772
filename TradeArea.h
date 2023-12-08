//Audrey Koffi-300263639
//Tamer Verir-300177023

#include <iostream>
#include <list>
#include <string>
#include "Card.h" 
#include "CardFactory.h"

class TradeArea {
private:
    std::list<Card*> cards; // Cartes dans TradeArea

public:
    // Constructeur 
    TradeArea(std::istream& in, const CardFactory* factory) {
      
    }

    // Opérateur pour ajouter une carte à tradearea
    TradeArea& operator+=(Card* card) {
        cards.push_back(card);
        return *this;
    }

    bool legal(Card* card) {
        // Interroger les cartes de la zone commerciale et vérifier si une carte du même bean est déjà présente.
        for (const auto& existingCard : cards) {
            if (existingCard->getName() == card->getName()) {
                return true;
            }
        }
        return false;
    }

    // Fonction permettant d'échanger une carte par son nom de bean
    Card* trade(const std::string& beanName) {
        // Interroger les cartes de tradearea et retirer la première carte dont le nom correspond à celui de bean.
        for (auto it = cards.begin(); it != cards.end(); ++it) {
            if ((*it)->getName() == beanName) {
                Card* tradedCard = *it;
                cards.erase(it);
                return tradedCard;
            }
        }
        return nullptr; // Retourne nullptr si aucune carte avec le nom du bean spécifié n'est trouvée
    }

    // Fonction permettant d'obtenir le nombre de cartes dans TradeArea
    int numCards() const {
        return cards.size();
    }

    // Fonction friend pour l'opérateur d'insertion afin d'imprimer les cartes de tradearea dans un flux d'informations.
    friend std::ostream& operator<<(std::ostream& os, const TradeArea& tradeArea) {
        for (const auto& card : tradeArea.cards) {
            os << *card << " "; 
        }
        return os;
    }
};
