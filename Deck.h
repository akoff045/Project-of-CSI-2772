#include <iostream>
#include <vector>
#include <ostream>
#include <istream>
#include "Card.h"  

class Deck: public std::vector<Card>{
public:
    Deck() = default; // Constructeur par défaut
     Card* draw(){
        return topCard;
     }
    
};

//     Card* draw() {
    //     if (!this->empty()) {
    //         Card* topCard = this->back(); // Récupérer la carte supérieure
    //         this->pop_back(); // Supprimer la carte du dessus
    //         return topCard;
    //     }
    //     return nullptr; // Retourner nullptr si le deck est vide
    // }

    // friend std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    //     for (const auto& card : deck) {
    //         out << *card << " "; // Afficher chaque carte du deck
    //     }
    //     return out;
    // }

    // Deck(std::istream& is, const CardFactory* factory) {
    //     while (is) {
    //         std::string cardName;
    //         is >> cardName; // Lire le nom de la carte depuis le flux

    //         if (cardName.empty()) {
    //             break; // Quitter si aucune carte à lire
    //         }

    //         // Utiliser le CardFactory pour créer une carte en fonction du nom lu depuis le flux
    //         Card* newCard = factory->getCard(cardName);

    //         // Ajouter la carte au deck
    //         if (newCard != nullptr) {
    //             this->push_back(newCard); // Ajouter la carte au deck
    //         }
    //     }
    // }
