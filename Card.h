#include <iostream>
#include <string>

class Card {
public:
    virtual int getCardsPerCoin(int coins) const = 0;// Méthode qui retourne 
    virtual std::string getName() const = 0; // Méthode pour afficher le nom d'une carte
    virtual void print(std::ostream& out) const = 0;// Méthode pour Imprimer le premier caractère du nom d'une carte

    virtual ~Card() = default; // Destructeur virtuel

    friend std::ostream& operator<<(std::ostream& out, const Card& card) {
        card.print(out);
        return out;
    }
};

class Blue : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        
        const int coinsPerCard[] = {0, 4, 6, 8, 10}; // Tableau contenant les différents nombres de cartes à un index qui correspond au nombre de pièces
        const int maxCoins = 4; // Nombre maximum de pièces de monnaie pouvant être attribuées
        
        if (coins <= 0) {
        return 0;       // On écarte le cas négatif  
        }else if (coins > maxCoins) {

        return coinsPerCard[maxCoins]; // On retourne le nombre de cartes pour le nombre maximal de pièces 
         } 
         
         else {

        return coinsPerCard[coins]; // Renvoie le nombre de cartes pour le nombre spécifique de pièces
    }
    }

    std::string getName() const override {
        return "Blue"; // Retourne le nom complet de Blue
    }

    void print(std::ostream& out) const override {
        out << "B"; // Retourne le premier caractère de Blue
    }
    
};

class Chili : public Card {
public:
    int getCardsPerCoin(int coins) const override {
       const int coinsPerCard[] = {0, 3, 6, 8, 9}; // Tableau contenant les différents nombres de cartes à un index qui correspond au nombre de pièces
        const int maxCoins = 4; // Nombre maximum de pièces de monnaie pouvant être attribuées
        
        if (coins <= 0) {
        return 0;       // On écarte le cas négatif  
        }else if (coins > maxCoins) {

        return coinsPerCard[maxCoins]; // On retourne le nombre de cartes pour le nombre maximal de pièces 
         } 
         
         else {

        return coinsPerCard[coins]; // Renvoie le nombre de cartes pour le nombre spécifique de pièces
         }
    }

    std::string getName() const override {
        return "Chili"; // Retourne le nom complet de Chili
    }

    void print(std::ostream& out) const override {
        out << "C"; // Retourne le premier caractère de Chili
    }
   
};

class Stink : public Card {
public:
    int getCardsPerCoin(int coins) const override {
       const int coinsPerCard[] = {0, 3, 5, 7, 8}; // Tableau contenant les différents nombres de cartes à un index qui correspond au nombre de pièces
        const int maxCoins = 4; // Nombre maximum de pièces de monnaie pouvant être attribuées
        
        if (coins <= 0) {
        return 0;       // On écarte le cas négatif  
        }else if (coins > maxCoins) {

        return coinsPerCard[maxCoins]; // On retourne le nombre de cartes pour le nombre maximal de pièces 
         } 
         
         else {

        return coinsPerCard[coins]; // Renvoie le nombre de cartes pour le nombre spécifique de pièces
    }
    }

    std::string getName() const override {
        return "Stink"; // Retourne le nom complet de Stink
    }

    void print(std::ostream& out) const override {
        out << "S"; // Retourne le premier caractère de Stink
    }
   
};

class Green: public Card {
public:
    int getCardsPerCoin(int coins) const override {
       const int coinsPerCard[] = {0, 3, 5, 6, 7}; // Tableau contenant les différents nombres de cartes à un index qui correspond au nombre de pièces
        const int maxCoins = 4; // Nombre maximum de pièces de monnaie pouvant être attribuées
        
        if (coins <= 0) {
        return 0;       // On écarte le cas négatif  
        }else if (coins > maxCoins) {

        return coinsPerCard[maxCoins]; // On retourne le nombre de cartes pour le nombre maximal de pièces 
         } 
         
         else {

        return coinsPerCard[coins]; // Renvoie le nombre de cartes pour le nombre spécifique de pièces
         }
    }

    std::string getName() const override {
        return "Green"; // Retourne le nom complet de Green
    }

    void print(std::ostream& out) const override {
        out << "G"; // Retourne le premier caractère de Green
    }
   
};

class Soy : public Card {
public:
    int getCardsPerCoin(int coins) const override {
       const int coinsPerCard[] = {0, 2, 4, 6, 7}; // Tableau contenant les différents nombres de cartes à un index qui correspond au nombre de pièces
        const int maxCoins = 4; // Nombre maximum de pièces de monnaie pouvant être attribuées
        
        if (coins <= 0) {
        return 0;       // On écarte le cas négatif  
        }else if (coins > maxCoins) {

        return coinsPerCard[maxCoins]; // On retourne le nombre de cartes pour le nombre maximal de pièces 
         } 
         
         else {

        return coinsPerCard[coins]; // Renvoie le nombre de cartes pour le nombre spécifique de pièces
         }
    }

    std::string getName() const override {
        return "Soy"; // Retourne le nom complet de Soy
    }

    void print(std::ostream& out) const override {
        out << "S"; // Retourne le premier caractère de Soy
    }
   
};

class black : public Card {
public:
    int getCardsPerCoin(int coins) const override {
       const int coinsPerCard[] = {0, 2, 4, 5, 6}; // Tableau contenant les différents nombres de cartes à un index qui correspond au nombre de pièces
        const int maxCoins = 4; // Nombre maximum de pièces de monnaie pouvant être attribuées
        
        if (coins <= 0) {
        return 0;       // On écarte le cas négatif  
        }else if (coins > maxCoins) {

        return coinsPerCard[maxCoins]; // On retourne le nombre de cartes pour le nombre maximal de pièces 
         } 
         
         else {

        return coinsPerCard[coins]; // Renvoie le nombre de cartes pour le nombre spécifique de pièces
         }
    }

    std::string getName() const override {
        return "black"; // Retourne le nom complet de black
    }

    void print(std::ostream& out) const override {
        out << "b"; // Retourne le premier caractère de black
    }
   
};

class Red : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        const int coinsPerCard[] = {0, 0, 2, 3, 0}; // Tableau contenant les différents nombres de cartes à un index qui correspond au nombre de pièces
        const int maxCoins = 4; // Nombre maximum de pièces de monnaie pouvant être attribuées
        
        if (coins <= 0) {
        return 0;       // On écarte le cas négatif  
        }else if (coins > maxCoins) {

        return coinsPerCard[maxCoins]; // On retourne le nombre de cartes pour le nombre maximal de pièces 
         } 
         
         else {

        return coinsPerCard[coins]; // Renvoie le nombre de cartes pour le nombre spécifique de pièces
         }
    }

    std::string getName() const override {
        return "Red"; // Retourne le nom complet de Red
    }

    void print(std::ostream& out) const override {
        out << "R"; // Retourne le premier caractère de Red
    }
   
};

class garden: public Card {
public:
    int getCardsPerCoin(int coins) const override {
        // Implémenter la logique pour Blue
        // Retourner le nombre de cartes nécessaires pour obtenir les pièces
    }

    std::string getName() const override {
        return "garden"; // Retourne le nom complet de Rgarden
    }

    void print(std::ostream& out) const override {
        out << "g"; // Retourne le premier caractère de garden
    }
   
};