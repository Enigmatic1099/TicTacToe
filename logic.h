#include "headers.h"

class Logic{
public:
    Logic() = default;

    bool winChecker(char (&arr)[3][3]); // a function for checking if someone has won or not
        bool rulesForWin(char (&arr)[3][3]);// a function that contains all the rules of the game
    bool drawChecker(char (&arr)[3][3]);//this function checks of the game is draw or not
    bool inputChecker(unsigned int input, char (&arr)[3][3], char &ch);// this function check if both players insert the propper inputs
    void changer_placer(unsigned int i, unsigned int j, char (&arr)[3][3], char ch);// this function changes the elements of the arr[3][3]
        bool wrongInputCharacterChecker(char (&arr)[3][3], unsigned int i, unsigned int j);// this function check if the element that we want to insert to is empty or occupied
    void changerCaller_inputMAker(unsigned int input, char (&arr)[3][3], char ch);// this functions calculates the cordinate of the input for the array
    void setCleaner();
private:
//  this set is for inserting the inputs for checking duplicate in input check
    std::set<unsigned int> set;
};
bool Logic::rulesForWin(char (&arr)[3][3]){
    if(arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] && arr[0][0] != ' '){
        std::cout << "==== " << arr[0][0] << " Wins ====" << std::endl;
        return true;
    }
    else if(arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && arr[1][0] != ' '){
        std::cout << "==== " << arr[1][0] << " Wins ====" << std::endl;
        return true;
    }
    else if(arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && arr[2][0] != ' '){
        std::cout << "==== " << arr[2][0] << " Wins ====" << std::endl;
        return true;
    }
    else if(arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[0][0] != ' '){
        std::cout << "==== " << arr[0][0] << " Wins ====" << std::endl;
        return true;
    }
    else if(arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && arr[0][1] != ' '){
        std::cout << "==== " << arr[0][1] << " Wins ====" << std::endl;
        return true;
    }
    else if(arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && arr[0][2] != ' '){
        std::cout << "==== " << arr[0][2] << " Wins ====" << std::endl;
        return true;
    }
    else if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' '){
        std::cout << "==== " << arr[0][0] << " Wins ====" << std::endl;
        return true;
    }
    else if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' '){
        std::cout << "==== " << arr[0][2] << " Wins ====" << std::endl;
        return true;
    }
    return false;
}
bool Logic::wrongInputCharacterChecker(char (&arr)[3][3], unsigned int i, unsigned int j){
    if(arr[i][j] != ' '){
        return true;
    }
    return false;
}
bool Logic::drawChecker(char (&arr)[3][3]){
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(arr[i][j] == ' ')
                return false;
        }
    }
    std::cout << "======Draw======" << std::endl;
    return true;
}
bool Logic::winChecker(char (&arr)[3][3]){
    if(rulesForWin(arr)){return true;}
    return false;
}
bool Logic::inputChecker(unsigned int input, char (&arr)[3][3], char &ch){
    if(input > 9 || input < 1){
        std::cout << "please Enter a number through 1 to 9" << std::endl;
        return true;
    }
    else{
        auto iter = set.find(input);
        if(iter == set.end()){
            set.insert(input);
        }
        else{
            std::cout << "dont select already selected block" << std::endl;
            return true;
        }
    }
    return false;
}
void Logic::changer_placer(unsigned int i, unsigned int j, char (&arr)[3][3], char ch){
    if(!wrongInputCharacterChecker(arr, i, j)){
        arr[i][j] = ch;
    }
}
void Logic::changerCaller_inputMAker(unsigned int input, char (&arr)[3][3], char ch){
    switch(input){
        case 1:
            changer_placer(0, 0, arr, ch);
            break;
        case 2:
            changer_placer(0, 1, arr, ch);
            break;
        case 3:
            changer_placer(0, 2, arr, ch);
            break;
        case 4:
            changer_placer(1, 0, arr, ch);
            break;
        case 5:
            changer_placer(1, 1, arr, ch);
            break;
        case 6:
            changer_placer(1, 2, arr, ch);
            break;
        case 7:
            changer_placer(2, 0, arr, ch);
            break;
        case 8:
            changer_placer(2, 1, arr, ch);
            break;
        case 9:
            changer_placer(2, 2, arr, ch);
            break;
    }
}
void Logic::setCleaner(){
    set.erase(set.begin(), set.end());
}