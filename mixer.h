#include "headers.h"
#include "player.h"
#include "board.h"
#include "logic.h"
Player player; Board board; Logic logic;


void mixer(){
    bool isItOTurnYet = false;
    int input;
    char ch;
    char moreRound;
    
    while(true){
        ch = player.turn_specifier(isItOTurnYet);
        board.printer();
        std::cout << "It's " << ch << "'s turn: ";
        std::cin >> input;
        system("clear");
        //checking the input if condition is false call turn specifier again to revert the ch(X or O)
        if(logic.inputChecker(input, board.arr, ch)){
            std::cin.get();
            system("clear");
            ch = player.turn_specifier(isItOTurnYet);
            continue;
        }
        // input checker satisfied the go for changes
        logic.changerCaller_inputMAker(input, board.arr, ch);
        //check for win or draw
        if(logic.winChecker(board.arr) || logic.drawChecker(board.arr)){
            board.printer();
            std::cout << "================" << std::endl;
            board.defaultArrayMaker();
            logic.setCleaner();
            std::cin.get();
            std::cout << "One More Time [Y/N] ";
            std::cin >> moreRound;
            switch (moreRound)
            {
            case 'Y':
            case 'y':
                mixer();
                break;
            case 'N':
            case 'n':
                std::cout << "have a nice day!";
                break;
            default:
                std::cout << "wrong input!\nTry again: ";
                break;
            }
            //system("clear");
            break;
        }
    }
}