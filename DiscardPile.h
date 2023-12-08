//Audrey Koffi-300263639
//Tamer Verir-300177023

#include <iostream>
#include <vector>
#include "Card.h"
#include "CardFactory.h" 

class DiscardPile {
public:
    DiscardPile& operator+=(Card* card);// Ajoute la carte éliminée à la pile de cartes éliminées
    Card* pickUp();// Renvoie et supprime la carte supérieure de la pile au rebut
    Card* top();// Renvoie mais ne supprime pas la carte supérieure de la pile au rebut
    void print(std::ostream& out) const;// Insère toutes les cartes de DiscardPile dans std::ostream
    friend std::ostream& operator<<(std::ostream& out, const DiscardPile& discardPile); // Insère seulement la carte supérieure de la pile au rebut dans un flux std::ostream
    DiscardPile(std::istream& in, const CardFactory* factory);// Constructeur qui accepte un flux istream et construit un objet de type DiscardPile à partir du fichier

// Déclaration de la classe DiscardPile avec un membre privé std::vector<Card*> pile
private:
    std::vector<Card*> pile;
};

DiscardPile::DiscardPile(std::istream& in, const CardFactory* factory) {// Constructeur qui construit un objet de type DiscardPile à partir d'un fichier istream
    int cardIndex;
    in >> cardIndex;

    while (cardIndex != -1) {// On lit les indices des cartes à partir du fichier et ajoute les cartes à la pile des cartes éliminées
        pile.push_back(factory->createCard(cardIndex));
        in >> cardIndex;
    }
}

DiscardPile& DiscardPile::operator+=(Card* card) {//  Ajoute une carte à la pile des cartes éliminées
    pile.push_back(card);
    return *this;// Renvoie une référence vers l'objet DiscardPile actuel pour permettre les opérations en chaîne
}


Card* DiscardPile::pickUp() {// Récupère et supprime la carte supérieure de la pile des cartes éliminées
    if (!pile.empty()) {
        Card* topCard = pile.back();
        pile.pop_back();
        return topCard;
    } else {
        return nullptr; // Si la pile est vide
    }
}

Card* DiscardPile::top() {// Retourne la carte se trouvant au dessus du deck mais ne la supprime pas 
    if (!pile.empty()) {
        return pile.back();
    } else {
        return nullptr; // Retourne nullptr si la pile est vide
    }
}

void DiscardPile::print(std::ostream& out) const {// Insère toutes les cartes de la pile dans un flux std::ostream
    for (const auto& card : pile) {
        out << *card << " ";
    }
}

std::ostream& operator<<(std::ostream& out, const DiscardPile& discardPile) {// Surcharge de l'opérateur d'insertion pour insérer seulement la carte supérieure de la pile de défausse dans un flux std::ostream
    if (!discardPile.pile.empty()) {
        out << *discardPile.pile.back();
    }
    return out;
}


