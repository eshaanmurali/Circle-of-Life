#ifndef TILE_H
#define TILE_H

class Tile
{
    private:
        char _color;
    public:
        // Constructors
        Tile();
        Tile(char);

        // Setter
        void setColor(char);
        char getColor();

};

#endif