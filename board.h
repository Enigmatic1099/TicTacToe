#include "headers.h"

class Board{
public:
// constructor for building the default array
    Board(){
        defaultArrayMaker();
    }
    void defaultArrayMaker();
    void printer();
    
    char arr[3][3];
};
// board printer
void Board::printer(){
        std::cout << "  " << arr[0][0] << "  |  " << arr[0][1] << " |  " << arr[0][2] << "\n"" ----|----|----\n "
                  " " << arr[1][0] << "  |  " << arr[1][1] << " |  " << arr[1][2] << "\n"" ----|----|----\n "
                 " " << arr[2][0] << "  |  " << arr[2][1] << " |  " << arr[2][2] << std::endl;
}
// defaultArrayMaker
void Board::defaultArrayMaker(){
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            arr[i][j] = ' ';
        }
    }
}
