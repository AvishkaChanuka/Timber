#include <sstream>
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
    spriteBee.setPosition(-100,800);

    bool beeActive = false;

    float beeSpeed = 0.0f;

    //Cloud
    Texture textureCloud;
    textureCloud.loadFromFile("../graphics/cloud.png");

    Sprite spriteCloud1, spriteCloud2, spriteCloud3;

    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    spriteCloud1.setPosition(-500,0);
    spriteCloud2.setPosition(-500,250);
    spriteCloud3.setPosition(-500,500);

    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;

    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    Clock clock;

    bool paused = true;

    int score = 0;

    Text messageText, scoreText;

    Font font;
    font.loadFromFile("../fonts/KOMIKAP_.ttf");

    messageText.setFont(font);
    scoreText.setFont(font);

    messageText.setString("Press Enter to Start");
    scoreText.setString("Score = 0");

    messageText.setCharacterSize(75);
    scoreText.setCharacterSize(100);

    messageText.setFillColor(Color::White);
    scoreText.setFillColor(Color::White);

    FloatRect textRect = messageText.getLocalBounds();

    messageText.setOrigin(textRect.left + textRect.width/2.0f,textRect.top + textRect.height/2.0f);
    messageText.setPosition(1920 / 2.0f,1080 / 2.0f);

    scoreText.setPosition(20,20);

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

        //Start the game
        if(Keyboard::isKeyPressed(Keyboard::Return))
        {
            paused = false;
        }

        /*
         *******************************************
         * Update the scene
         *******************************************
        */

        if(!paused) {

            //Measure Time
            Time dt = clock.restart();

            //Set up the bee
            if (!beeActive) {
                //How fast bee move
                srand((int) time(0));
                beeSpeed = (rand() % 200) + 200;

                //How height is the bee
                srand((int) time(0) * 10);
                float height = (rand() % 500) + 500;
                spriteBee.setPosition(2000, height);

                beeActive = true;
            } else // Move the bee
            {
                spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()),
                                      spriteBee.getPosition().y);

                if (spriteBee.getPosition().x < -10) {
                    //Set it up ready to be a whole new bee next frame
                    beeActive = false;
                }
            }

            //Manage clouds
            //Cloud 1
            if (!cloud1Active) {

                srand((int) time(0) * 10);
                cloud1Speed = (rand() % 200);

                srand((int) time(0) * 10);
                float height = (rand() % 150);
                spriteCloud1.setPosition(-200, height);

                cloud1Active = true;
            } else {
                spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()),
                                         spriteCloud1.getPosition().y);

                if (spriteCloud1.getPosition().x > 1920) {

                    cloud1Active = false;

                }
            }

            //Cloud 2
            if (!cloud2Active) {

                srand((int) time(0) * 20);
                cloud2Speed = (rand() % 200);

                srand((int) time(0) * 20);
                float height = (rand() % 300) - 150;
                spriteCloud2.setPosition(-200, height);

                cloud2Active = true;
            } else {
                spriteCloud2.setPosition(spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()),
                                         spriteCloud2.getPosition().y);

                if (spriteCloud2.getPosition().x > 1920) {

                    cloud2Active = false;

                }
            }

            //Cloud 3
            if (!cloud3Active) {

                srand((int) time(0) * 30);
                cloud3Speed = (rand() % 200);

                srand((int) time(0) * 30);
                float height = (rand() % 450) - 150;
                spriteCloud3.setPosition(-200, height);

                cloud3Active = true;
            } else {
                spriteCloud3.setPosition(spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()),
                                         spriteCloud3.getPosition().y);

                if (spriteCloud3.getPosition().x > 1920) {

                    cloud3Active = false;

                }
            }

            //Update score text
            std::stringstream ss;
            ss << "Score = " << score;
            scoreText.setString(ss.str());
        }//End !paused
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

        window.draw(scoreText);

        if(paused){
            window.draw(messageText);
        }

        //Show everything we just drew
        window.display();
    }

    return 0;
}