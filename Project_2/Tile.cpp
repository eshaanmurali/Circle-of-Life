#include "Tile.h"

Tile::Tile()
{
    _color = ' ';
}

Tile::Tile(char c)
{
    _color = c;
}

void Tile::setColor(char c){
    _color = c;
}

char Tile::getColor(){
    return _color;
}