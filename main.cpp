#include <SFML/Graphics.hpp>

using namespace sf;

int main(){

    VideoMode vm(1920,1080);

    RenderWindow window(vm,"Timber",Style::Fullscreen);

    Texture textureBackground;
    textureBackground.loadFromFile("../graphics/background.png"); //add path according to the position of .exe file

    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0,0);

    while (window.isOpen())
    {

        /*
         *******************************************
         * Handle the player's input
         *******************************************
        */

        if(Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        /*
         *******************************************
         * Update the scene
         *******************************************
        */

        /*
         *******************************************
         * Draw the scene
         *******************************************
        */

        //Clear everything from the last frame
        window.clear();

        //Draw our game scene here
        window.draw(spriteBackground);

        //Show everything we just drew
        window.display();
    }

    return 0;
}