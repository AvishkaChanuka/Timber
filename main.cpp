#include <SFML/Graphics.hpp>

using namespace sf;

int main(){

    VideoMode vm(1920,1080);

    RenderWindow window(vm,"Timber",Style::Fullscreen);

    //Background Texture
    Texture textureBackground;
    textureBackground.loadFromFile("../graphics/background.png"); //add path according to the position of .exe file

    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0,0);

    //Tree
    Texture textureTree;
    textureTree.loadFromFile("../graphics/tree.png");

    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810,0);

    //bee
    Texture textureBee;
    textureBee.loadFromFile("../graphics/bee.png");

    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0,800);

    bool beeActive = false;

    bool beeSpeed = 0.0f;

    //Cloud
    Texture textureCloud;
    textureCloud.loadFromFile("../graphics/cloud.png");

    Sprite spriteCloud1, spriteCloud2, spriteCloud3;

    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    spriteCloud1.setPosition(0,0);
    spriteCloud2.setPosition(0,250);
    spriteCloud3.setPosition(0,500);

    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;

    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

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

        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);

        window.draw(spriteTree);

        window.draw(spriteBee);

        //Show everything we just drew
        window.display();
    }

    return 0;
}