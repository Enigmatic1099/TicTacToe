#include "headers.h"
#include "player.h"
#include "board.h"
#include "logic.h"
Player player; Board board; Logic logic;


void mixer(){
    bool isItOTurnYet = false;
    int input;
    char ch;
    
    while(true){
        ch = player.turn_specifier(isItOTurnYet);
        board.printer();
        std::cout << "It's " << ch << "'s turn: ";
        std::cin >> input;
        system("CLS");
        //checking the input if condition is false call turn specifier again to revert the ch(X or O)
        if(logic.inputChecker(input, board.arr, ch)){
            system("PAUSE");
            system("CLS");
            ch = player.turn_specifier(isItOTurnYet);
            continue;
        }
        // input checker satisfied the go for changes
        logic.changerCaller_inputMAker(input, board.arr, ch);
        //check for win or draw
        if(logic.winChecker(board.arr) || logic.drawChecker(board.arr)){
            board.printer();
            std::cout << "================" << std::endl;
            system("PAUSE");
            system("CLS");
            break;
        }
    }
}