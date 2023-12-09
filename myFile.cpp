//Audrey Koffi-300263639
//Tamer Verir-300177023

#include <iostream>
#include <fstream>
#include "CardFactory.h"
#include "Player.h"
#include "Table.h"
#include "Hand.h"
#include "Chain.h"
#include "TradeArea.h"

int main() {
    std::string player1Name, player2Name;
    std::cout << "Enter Player 1 name: ";
    std::cin >> player1Name;
    std::cout << "Enter Player 2 name: ";
    std::cin >> player2Name;

    CardFactory* cardFactory = CardFactory::getFactory();
    Deck deck = cardFactory->getDeck();
    TradeArea* tradearea;

    Player player1(player1Name);
    Player player2(player2Name);

    Chain chain1;
    Chain chain2;

    Hand* player1Hand;
    Hand* player2Hand;

    for (int i = 0; i < 5; ++i) {
        player1Hand += deck.draw();
        player2Hand += deck.draw();
    }

    Table table(player1, player2, deck);

    while (!deck.empty()) {
        std::cout << table << std::endl; 


        for (int i = 0; i < 2; ++i) {
            Player& currentPlayer = (i == 0) ? player1 : player2;
            Hand& currentHand = (i == 0) ? player1Hand : player2Hand;
            Chain& currentChain = (i == 0) ? chain1 : chain2;

            currentHand* += deck.draw();
            
            currentHand.play();
            if (true) {
                currentHand.play();

                // Check if the chain is ended again
                if (true) {
                    
                }
            }

            std::cout << currentHand;

            for (int i = 1; i <= 4; ++i) {
                tradearea* += deck.draw();
            }
            currentHand.play();
            currentHand.play();
        }

        if (true) {
            std::ofstream saveFile("save_game.txt");
            saveFile << table;  
            saveFile.close();
            return 0;
        }
    }

    std::string winningPlayer;
    if (table.win(winningPlayer)) {
        std::cout << "Player " << winningPlayer << " wins!" << std::endl;
    }

    return 0;
}
