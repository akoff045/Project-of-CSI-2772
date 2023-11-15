#include <iostream>
#include <ostream>
#include <istream>
#include <vector>
# include "Card.h"
#include "Chain.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Table.h"
#include "TradeArea.h"
#include "Coins.h"
#include "Hand.h" 


 Player: public std  {
    public: 
    Player(std::string&){

    }
    std :string getName();
    int getNumCoins() ;
    Player& operator+=(int );
    int getMaxNumChains();
    Chain& operator[](int i);
    void buyThirdChain();
    void buyThirdChain();
    void printHand(std::ostream&, bool);
    Player(istream&, const CardFactory* );


    }
    // La classe Player aura les fonctions suivantes :
// - Player( std::string& ) constructeur qui crée un objet de type Player avec un nom
// donné.
// - std:string getName() obtenir le nom du joueur.
// - int getNumCoins() obtenir le nombre de pièces actuellement détenues par le joueur.
// - Player& operator+=(int ) ajoute un nombre de pièces
// - int getMaxNumChains()renvoie 2 ou 3.
// - int getNumChains()renvoie le nombre de chaînes non nulles.
// - Chain& operator[](int i) renvoie la chaîne en position i.
// - void buyThirdChain()ajoute une troisième chaîne vide au joueur pour deux pièces. La
// fonction réduit le nombre de pièces par deux pour le joueur. Si le joueur n'a pas suffisamment de
// pièces alors une exception NotEnoughCoins est soulevée.
// - void printHand(std::ostream&, bool) affiche la première carte de la main du
// joueur (avec l'argument False) ou l'ensemble de la main du joueur (avec l'argument True) dans le
// flux correspondant ostream.
// - Ajouter également l'opérateur d'insertion pour afficher un joueur (Player) dans
// std::ostream. Le nom du joueur, le nombre de pièces que possède le joueur et chacune des
// chaînes (2 ou 3, certaines peuvent être vides) doivent être affichés. Hand est affichée à l’aide
// d’une autre fonction. L'affichage du joueur peut se présenter comme suit :
// Dave 3 coins
// Red R R R R
// Blue B
// - Player possède un constructeur qui accepte un flux istream et construit un objet de type
// Player à partir du fichier :
// Player(istream&, const CardFactory* );