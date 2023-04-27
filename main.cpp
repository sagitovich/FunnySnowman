#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include "Hero.hpp"
#include "Gift.hpp"
#include "Menu.hpp"
#include <chrono>
#include <thread>
#include <iostream>
using namespace std;

int main()
{
    int WindowX = 900; int WindowY = 1200; 
    sf::RenderWindow window(sf::VideoMode(WindowX, WindowY), "Sagitov project");
    sf::Music music; music.openFromFile("src/ImgMusFont/HideAndSeek.ogg"); 
    
    sf::Text GiftCount, LoseCount; 
    sf::Font font;
    font.loadFromFile("src/ImgMusFont/font.ttf");
    GiftCount.setFont(font);                                LoseCount.setFont(font);
    GiftCount.setCharacterSize(70);                         LoseCount.setCharacterSize(70);
    GiftCount.setFillColor(sf::Color::Red);                 LoseCount.setFillColor(sf::Color::Red);
    GiftCount.setStyle(sf::Text::Bold);                     LoseCount.setStyle(sf::Text::Bold);
    GiftCount.setPosition(WindowX/4 - 50, WindowY - 90);    LoseCount.setPosition(WindowX/2 + 50, WindowY - 90);


    Hero Snowman = Hero(sf::Sprite()); Snowman.setWin(WindowX, WindowY); Snowman.setHero(); Snowman.setPos(2); // создание героя
   
    double Vy1 = 25;                  double Vy2 = 20;                  double Vy3 = 15;
    Gift Gift1 = Gift(sf::Sprite());  Gift Gift2 = Gift(sf::Sprite());  Gift Gift3 = Gift(sf::Sprite());  // cоздание подарков
    Gift1.setWin(WindowX, WindowY);   Gift2.setWin(WindowX, WindowY);   Gift3.setWin(WindowX, WindowY);
    Gift1.SetGift(1, Vy1);            Gift2.SetGift(2, Vy2);            Gift3.SetGift(3, Vy3);
    
    float time = 0; int Point = 0; int Lose = 0; bool FlagMenu = true;
    bool leftFlag = false; bool leftFlagDrob = true; bool rightFlag = false; bool rightFlagDrob = true;
    while (window.isOpen())
    {
        sf::Event event;
        while ((window.pollEvent(event)))
        {if ((event.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) window.close();}

        if (FlagMenu) {FlagMenu = menu(window);}
        else
        {
            
        if (music.getStatus() != sf::SoundSource::Playing) {music.play();}  
        Gift1.MoveGift(Snowman, Point, Lose); Gift2.MoveGift(Snowman, Point, Lose); Gift3.MoveGift(Snowman, Point, Lose); // движение подарков
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (leftFlag == false) // если нажата Left и герой на 2 -> поместить на 1 +
        && (Snowman.m_HeroSprite.getPosition() == Snowman.getPos(2))) 
        {Snowman.setPos(1); leftFlag = true;}
        if (event.type == sf::Event::KeyReleased) {leftFlagDrob = true; leftFlag = false;}

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (leftFlag == false)  // если нажата Left и герой на 3 -> поместить на 2
        && (Snowman.m_HeroSprite.getPosition() == Snowman.getPos(3))) 
        {Snowman.setPos(2); leftFlag = true;}
        if (event.type == sf::Event::KeyReleased) {leftFlagDrob = true; leftFlag = false;}

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (rightFlag == false)  // если нажата Right и герой на 1 -> поместить на 2
        && (Snowman.m_HeroSprite.getPosition() == Snowman.getPos(1))) 
        {Snowman.setPos(2); rightFlag = true;}
        if (event.type == sf::Event::KeyReleased) {rightFlagDrob = true; rightFlag = false;}

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (rightFlag == false)  // если нажата Right и герой на 2 -> поместить на 3
        && (Snowman.m_HeroSprite.getPosition() == Snowman.getPos(2))) 
        {Snowman.setPos(3); rightFlag = true;}
        if (event.type == sf::Event::KeyReleased) {rightFlagDrob = true; rightFlag = false;}

        sf::Texture t; t.loadFromFile("src/ImgMusFont/night.jpg"); sf::Sprite s(t);         // загрузка фона
        GiftCount.setString("Score: " + std::to_string(Point));
        LoseCount.setString("Health: " + std::to_string(3 - Lose));
       
        if (Point >= 10) // счёт 
        {
            sf::Texture YouWin; YouWin.loadFromFile("src/ImgMusFont/YouWin.jpg"); sf::Sprite Win(YouWin);
            Lose = 0; Vy1 = 0; Vy2 = 0; Vy3 = 0; music.stop(); window.clear(); window.draw(Win); window.display();
            
        }
        else if(Lose >= 3) // потери
        {
            sf::Texture GameOver; GameOver.loadFromFile("src/ImgMusFont/GameOver.jpg"); sf::Sprite Over(GameOver);
            Point = 0; Vy1 = 0; Vy2 = 0; Vy3 = 0; music.stop(); window.clear(); window.draw(Over); window.display();
            
        }
        else if (Point < 10 && Lose < 3)
        {
            window.clear(); window.draw(s);     // отрисовка фона
            window.draw(GiftCount); window.draw(LoseCount);           // вывод счёта
            window.draw(Gift1.m_GiftSprite); window.draw(Gift2.m_GiftSprite); window.draw(Gift3.m_GiftSprite);
            window.draw(Snowman.m_HeroSprite);  // отрисовка героя
            window.display();  
        } 

        time += 0.01; std::this_thread::sleep_for(std::chrono::milliseconds(100));    // задержка
        }
    }
    return 0;
}
