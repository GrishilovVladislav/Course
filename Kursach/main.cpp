#include <SFML/Graphics.hpp>

using namespace sf;
int ground = 3000;
const int mapH = 33;
const int mapW = 182;
float offsetX = 0, offsetY = 0;

void menu(RenderWindow& window) {
    Texture T1, T2, T3, menuBackground, about;
    T1.loadFromFile("1.png");
    T2.loadFromFile("2.png");
    T3.loadFromFile("3.png");
    about.loadFromFile("about.png");
    menuBackground.loadFromFile("Back.png");
    Sprite menu1(T1), menu2(T2), menu3(T3), menuBg(menuBackground), info(about);
    bool isMenu = 1;
    int menuNum = 0;
    menu1.setPosition(50, 30);
    menu2.setPosition(75, 90);
    menu3.setPosition(50, 150);
    info.setPosition(0, 0);
    while (isMenu)
    {
        menu1.setColor(Color::White);
        menu2.setColor(Color::White);
        menu3.setColor(Color::White);
        menuNum = 0;
        window.clear(Color(129, 181, 221));

        if (IntRect(50, 30, 300, 50).contains(Mouse::getPosition(window))) {
            menu1.setColor(Color::Blue);
            menuNum = 1;
        }
        if (IntRect(75, 90, 300, 50).contains(Mouse::getPosition(window))) {
            menu2.setColor(Color::Blue);
            menuNum = 2;
        }
        if (IntRect(50, 150, 300, 50).contains(Mouse::getPosition(window))) {
            menu3.setColor(Color::Blue);
            menuNum = 3;
        }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1) {
                isMenu = false;
            }
            if (menuNum == 2) {   
                window.draw(info);
                window.display();               
                while (!Keyboard::isKeyPressed(Keyboard::Escape));
            }
            if (menuNum == 3) { 
                window.close(); 
                isMenu = false;
            }

        }

        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);

        window.display();
    }
}

String TileMap[mapH] = {
"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
"CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC",
"            L                                                                                                                                                    L                    ",
"            t                                                                                                                                                    t                    ",
"            T                                                                                                            ccccc                                   T                    ",
"            T                                                                                                                                                    T                    ",
"            T                                                                                                                                                    T                    ",
"            T                               HHH    HHHH  HH     HH    HHH                                RRRRRR                           RRRRRRRRRR       RR    T                    ",
"            t                               H  H   H     H H   H H   H   H                                                                                       t                    ",
"            T                ccccc          H   H  HHH   H H   H H   H   H                                                                                       T                    ",
"            T      R                        H  H   H     H  H H  H   H   H                                              RRRRRR                                   T                    ",
"            T      R                        HHH    HHHH  H   H   H    HHH      RRRR               RRRRR               ccccc                                      T                    ",
"            T      R                                                                                                                                  RR         T                    ",
"            t      RRR                                                                                                                                           t                    ",
"            T                                                    RRRRRR                       R                                                                  T                    ",
"            T                                                                                 R                                                                  T                    ",
"            T               RRR                    R       R                                 RRR                                                    RR           T                    ",
"            T      R                             RRR       RRR                              RRRRR                                                                T                    ",
"            T      R                               R ccccc R                                                                                                     T                    ",
"            M      R                               RRRRRRRRR                                                                                        RRRRR        M                    ",
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD",
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD",
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD",
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD",
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD",
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD",
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD",
};
//String BufferTileMap[mapH];

class Player {

public:

    int coins=0;
    float dx, dy;
    FloatRect rect;
    bool onGround;
    Sprite sprite;
    float currentFrame;

    Player(Texture& image)
    {
        sprite.setTexture(image);
        rect = FloatRect(30*17, 17*17, 50, 50);
        sprite.setTextureRect(IntRect(0, 35, 50, 50));
        dx = dy = 0;
        currentFrame = 0;
    }


    void update(float time)
    {
        sprite.setTextureRect(IntRect(0, 35, 50, 50));
        rect.left += dx * time;
        Collision(0);
 

        if (!onGround)
        {
            dy = dy + 0.0005 * time;
        }
        rect.top += dy * time;
        onGround = false;
        Collision(1);


        if (rect.top > ground) {
            rect.top = ground;
            dy = 0;
            onGround = true;
        }
        currentFrame += 0.005 * time;
        if (currentFrame > 10) {
            currentFrame -= 10;
        }

        if (dx > 0) {
            sprite.setTextureRect(IntRect(50 * int(currentFrame), 100, 50, 50));
        }
        if (dx < 0) {
            sprite.setTextureRect(IntRect(50 * int(currentFrame) + 50, 100, -50, 50));
        }
        sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

        dx = 0;

    }

    void Collision(int num)
    {

        for (int i = rect.top / 17; i < (rect.top + rect.height) / 17; i++)
            for (int j = rect.left / 17; j < (rect.left + rect.width) / 17; j++)
            {
                if ((TileMap[i][j] == 'R') || (TileMap[i][j] == 'M') || (TileMap[i][j] == 'T') || (TileMap[i][j] == 't') || (TileMap[i][j] == 'G') || (TileMap[i][j] == 'D'))
                {
                    if (dy > 0 && num == 1)
                    {
                        rect.top = i * 17 - rect.height;
                        dy = 0; 
                        onGround = true;
                    }
                    if (dy < 0 && num == 1)
                    {
                        rect.top = i * 17 + 17;   dy = 0;
                    }
                    if (dx > 0 && num == 0)
                    {
                        rect.left = j * 17 - rect.width;
                    }
                    if (dx < 0 && num == 0)
                    {
                        rect.left = j * 17 + 17;
                    }
                }

                if (TileMap[i][j] == 'c') {
                    TileMap[i][j]=' '; 
                    coins++;
                }
            }

    }
    


};

class Enemy
{

public:
    float dx, dy;
    FloatRect rect;
    Sprite sprite;
    float currentFrame;
    bool life;


    void set (Texture& image, int x, int y)
    {
        sprite.setTexture(image);
        rect = FloatRect(x, y, 26, 23);
        dx = 0.05;
        currentFrame = 0;
        life = true;
    }

    void update(float time)
    {
        rect.left += dx * time;

        Collision();


        currentFrame += time * 0.005;
        if (currentFrame > 2) {
            currentFrame -= 2;
        }

        sprite.setTextureRect(IntRect(155 + 26 * int(currentFrame), 27, 26 , 23));
        if (!life) {
            sprite.setTextureRect(IntRect(207, 28, 25, 22));
        }


        sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

    }


    void Collision()
    {

        for (int i = rect.top / 17; i < (rect.top + rect.height) / 17; i++) {
            for (int j = rect.left / 17; j < (rect.left + rect.width) / 17; j++) {
                if ((TileMap[i][j] == 'M') || (TileMap[i][j] == 'R') || (TileMap[i][j] == 'T'))
                {
                    if (dx > 0)
                    {
                        rect.left = j * 17 - rect.width;
                        dx *= -1;
                    }
                    else if (dx < 0)
                    {
                        rect.left = j * 17 + 17;
                        dx *= -1;
                    }

                }
            }
        }
    }

};


int main()
{
    RenderWindow window(VideoMode(600, 350), "Platformer");

    menu(window);
    
    Image imageHero;
    imageHero.loadFromFile("Sprites.png");
    imageHero.createMaskFromColor(imageHero.getPixel(0, 0));
    Texture hero;
    hero.loadFromImage(imageHero);

    Image imageTiles;
    imageTiles.loadFromFile("Tiles.png");
    imageTiles.createMaskFromColor(imageTiles.getPixel(0, 0));
    Texture tiles;
    tiles.loadFromImage(imageTiles);

    Image imageMobs;
    imageMobs.loadFromFile("Mobs.png");
    imageMobs.createMaskFromColor(imageMobs.getPixel(0, 0));
    Texture mobs;
    mobs.loadFromImage(imageMobs);
    
    Sprite tile(tiles);

    bool GameOver=false;

    Clock clock;

    RectangleShape rec;

    /*  for (int i = 0; i < mapH; i++)
    {             
            BufferTileMap[i] = TileMap[i];        
    }
    */
    while (window.isOpen())
    {
        Player P(hero);
        Enemy E1;
        /*for (int i = 0; i < mapH; i++)
        {                    
                TileMap[i] = BufferTileMap[i];         
        }*/

        E1.set(mobs, 90 * 17, 24 * 17 - 6);

        window.clear();
        GameOver = false;
        menu(window);
        while (GameOver == false) {
            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time / 400;

            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }

            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                P.dx = -0.1;
            }

            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                P.dx = 0.1;
            }

            if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                if (P.onGround) {
                    P.dy = -0.35;
                    P.onGround = false;
                }
            }
            P.update(time);
            E1.update(time);

            if (P.rect.intersects(E1.rect))
            {
                if (E1.life) {
                    if (P.dy > 0) {
                        E1.dx = 0;
                        P.dy = -0.2;
                        E1.life = false;
                    }
                    else {
                        P.sprite.setColor(Color::Red);
                        GameOver = true;
                    }
                }
            }

            if (P.rect.left > 17 * 20 && P.rect.left < (183 - 28) * 17) {
                offsetX = P.rect.left - 250;
            }
            if (P.rect.top > 17 * 17) {
                offsetY = P.rect.top - 200;
            }

            window.clear(Color(175, 238, 238));


            for (int i = 0; i < mapH; i++)
                for (int j = 0; j < mapW; j++)
                {
                    if (TileMap[i][j] == 'G') {
                        tile.setTextureRect(IntRect(40, 20, 17, 17));
                    }

                    if (TileMap[i][j] == 'D') {
                        tile.setTextureRect(IntRect(40, 120, 17, 17));
                    }

                    if (TileMap[i][j] == 'T') {
                        tile.setTextureRect(IntRect(320, 100, 17, 17));
                    }

                    if (TileMap[i][j] == 't') {
                        tile.setTextureRect(IntRect(320, 80, 17, 17));
                    }

                    if (TileMap[i][j] == 'M') {
                        tile.setTextureRect(IntRect(340, 120, 17, 17));
                    }

                    if (TileMap[i][j] == 'L') {
                        tile.setTextureRect(IntRect(320, 20, 17, 17));
                    }

                    if (TileMap[i][j] == 'C') {
                        tile.setTextureRect(IntRect(280, 140, 17, 17));
                    }

                    if (TileMap[i][j] == 'x') {
                        tile.setTextureRect(IntRect(320, 140, 17, 17));
                    }

                    if (TileMap[i][j] == 'R') {
                        tile.setTextureRect(IntRect(120, 20, 17, 17));
                    }

                    if (TileMap[i][j] == 'H') {
                        tile.setTextureRect(IntRect(180, 0, 17, 17));
                    }

                    if (TileMap[i][j] == 'c') {
                        tile.setTextureRect(IntRect(140, 60, 17, 17));
                    }

                    if ((TileMap[i][j] == ' ') || (TileMap[i][j] == '0')) {
                        continue;
                    }

                    tile.setPosition(j * 17 - offsetX, i * 17 - offsetY);
                    window.draw(tile);
                }
            if (P.coins == 20) {
                GameOver = true;
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                GameOver = true;
            }
            window.draw(P.sprite);
            window.draw(E1.sprite);
            window.display();
        }
        
    }
}

    
    
