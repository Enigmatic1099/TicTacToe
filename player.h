
class Player{
public:
    //returns O
    Player() = default;
    char bigO(){
        return this->o;
    }
    // returns X
    char bigX(){
        return this->x;
    }
    char turn_specifier(bool &turner);
private:
    char o = 'O';
    char x = 'X';
};
// specifies turn of the players
char Player::turn_specifier(bool &turner){
    if(!turner){
    turner = true;
    return this->bigX();
    }
    else{
        turner = false;
        return this->bigO();
    }
}