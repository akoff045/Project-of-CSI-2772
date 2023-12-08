//Audrey Koffi-300263639
//Tamer Verir-300177023

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Chain.h"

class Player {
private:
    std::string name;// Nom du joueur
    int coins;// Coins du joueur
    std::vector<Chain_Base*> chains;//Vecteur qui store la chaîne du joueur 

public:
    Player(const std::string& playerName) : name(playerName), coins(0) { // Créé un objet joueur avec un nom et 2 chaînes par défaut 
        
        chains.push_back(new Chain<Blue>());
        chains.push_back(new Chain<Green>());
    }

    Player(std::istream& is, const CardFactory* factory) {  // Créé un objet joueur à partir d'un istream
        // Code à compléter...................................................
    }

    std::string getName() const {//Retourne le nom du joueur
        return name;
    }

    int getNumCoins() const {// Renvoie le nombre de pièces actuellement détenues par le joueur
        return coins;
    }

    Player& operator+=(int numCoins) {// Ajoute des coins à un joueur 
        coins += numCoins;
        return *this;
    }

    int getMaxNumChains() const { // Retourne le nombre maximum de chaîne possible pour un joueur
        return 3;
    }

    int getNumChains() const {//Retourne le nombre actuel de chaîne d'un joueur
        return chains.size();
    }

    Chain_Base& operator[](int i) const {//Retourne une chaîne se trouvant à un index spécifique 
        if (i < 0 || i >= chains.size()) {
            throw std::out_of_range("Invalid chain index");
        }
        return *chains[i];
    }

    void buyThirdChain() {
        if (coins < 2) {//On vérifie d'abord si le joueur possède assez de coins pour acheter une 3ème chaîne
            throw std::runtime_error("Not enough coins to buy a third chain");// Quand il n'en a pas assez, on renvoie un message d'erreur
        }

        coins -= 2;//Quand il en a assez on lui en prend 2 et on ajoute ensuite une chaîne à ses chaînes existantes
        chains.push_back(new Chain<Red>());
    }

    void printHand(std::ostream& out, bool showAll) const {
        out << name << " " << coins << " coins" << std::endl; // Affcihe le nom du joueur ainsi que le nombre de coins qu'il possède

        if (showAll) {//On vérifie si toutes les chaînes peuvent être montrées
            for (const auto& chain : chains) {//On affiche toutes les chaînes avce une loop for 
                out << *chain << " ";
            }
        } else {// Si toutes les chaînes ne sont pas à afficher, on vérifie si il y a au moins chaîne et on imprime sa valeur en coins sans afficher son contenu
            if (!chains.empty()) {
                out << chains[0]->sell() << " ";
            }
        }
        out << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& player) {//On affiche la main du joueur en utilisant la méthode printHand()
        player.printHand(out, true);
        return out;
    }

    

    ~Player() {//Destructeur
        for (auto& chain : chains) {
            delete chain;
        }
    }
};

