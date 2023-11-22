#include <iostream>
#include <vector>
#include "Card.h"
#ifndef DECK_H
#define DECK_H
class CardFactory; // Déclaration anticipée de CardFactory

class Deck : public std::vector<Card*> {
public:
    Deck(const CardFactory* factory);// Constructeur qui initialise le deck avec les cartes du factory
    Deck(std::istream& in, const CardFactory* factory); 
    ~Deck();// Destructeur qui libère la mémoire allouée aux cartes
    Card* draw();// Retourne et supprime la carte se trouvant au dessus du Deck
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck);// Surcharge de l'opérateur d'insertion pour insérer toutes les cartes du Deck dans un flux std::ostream

private:
    void initializeDeck(const CardFactory* factory); // Initialise le deck avec les cartes du factory
};
Deck() = default;//Constructeur par défaut
Deck::Deck(const CardFactory* factory) {// Constructeur Deck utilisant initializeDeck
    initializeDeck(factory);
}

Deck::Deck(std::istream& in, const CardFactory* factory) {// Constructeur Deck qui permet la construction d'un objet Deck à partir d'un fichier istream
    initializeDeck(factory);

    int cardIndex;
    in >> cardIndex;

    while (cardIndex != -1) {// Lit les indices des cartes à partir du fichier et ajoute les cartes au deck
        this->push_back(factory->createCard(cardIndex));
        in >> cardIndex;
    }
}

Deck::~Deck() {// Destructeur qui libère la mémoire allouée aux cartes
    for (auto& card : *this) {
        delete card;
    }
}

Card* Deck::draw() {//Retourne et supprime la carte au dessus du Deck
    if (!this->empty()) {
        Card* topCard = this->back();
        this->pop_back();
        return topCard;
    } else {
        return nullptr; // Si le Deck est vide
    }
}

Deck CardFactory::getDeck() {// Renvoie Deck avec toutes les cartes haricots dans un ordre aléatoire
    Deck deck;          // Crée un objet  Deck
    set(deck);          // Ajoute les cartes au deck
    shuffle(deck);      // Mélange le deck
    return deck;        // Retourne le deck final
}

std::ostream& operator<<(std::ostream& out, const Deck& deck) {// Surcharge de l'opérateur d'insertion pour insérer toutes les cartes du Deck dans un flux std::ostream
    for (const auto& card : deck) {
        out << *card << " ";
    }
    return out;
}

void Deck::initializeDeck(const CardFactory* factory) {//Iinitialise le deck avec les cartes du factory
    for (int i = 0; i < 104; ++i) {
        this->push_back(factory->createCard(i));
    }
}

#endif
