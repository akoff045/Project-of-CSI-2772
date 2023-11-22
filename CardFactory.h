#include <iostream>
#include <algorithm>  
#include <vector>
#include <ctime>      
#include <cstdlib>   
#include "Card.h"
#include "Deck.h"

class CardFactory {
public:
    static CardFactory* getFactory();// Instance de CardFactory
    Deck getDeck();//Renvoie Deck avec toutes les 104 cartes haricots dans un ordre aléatoire

private:
    CardFactory();// Constructeur privé qui permet d'empêcher l'instanciation directe
    void set(Deck& deck);// Méthode pour créer toutes les cartes haricots nécessaires
    void shuffle(Deck& deck); // Méthode pour mélanger le deck
    static CardFactory* instance; // Instance unique de CardFactory
};


CardFactory* CardFactory::instance = nullptr;// Initialise CardFactory à un pointeur null

CardFactory::CardFactory() {}//Constructeur

CardFactory* CardFactory::getFactory() {// Renvoie l'instance de CardFactory
    // Si l'instance n'existe pas, on la crée sinon on la renvoie
    if (!instance) {
        instance = new CardFactory();
    }
    return instance;
}

void CardFactory::set(Deck& deck) {// Créé toutes les cartes haricots nécessaires et les ajoute au deck
    deck.push_back(new Blue());
    deck.push_back(new Chili());
    deck.push_back(new Stink());
    deck.push_back(new Green());
    deck.push_back(new Soy());
    deck.push_back(new black());
    deck.push_back(new Red());
    deck.push_back(new garden());
}

void CardFactory::shuffle(Deck& deck) {// Mélange le deck 
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // On utilise std::srand et std::random_shuffle pour mélanger le deck
    std::random_shuffle(deck.begin(), deck.end());
}
