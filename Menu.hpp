#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

bool menu(sf::RenderWindow &window)
{
    sf::Texture menuTexture1, menuTexture2, menuTexture3, backTexture, menuBackTexture, AbotProgrammTexture;
    menuTexture1.loadFromFile("src/ImgMusFont/33.png"); // играть
    menuTexture2.loadFromFile("src/ImgMusFont/22.png"); // о программе
    menuTexture3.loadFromFile("src/ImgMusFont/11.png"); // выход
    backTexture.loadFromFile("src/ImgMusFont/back.png"); // стрелка назад
    menuBackTexture.loadFromFile("src/ImgMusFont/MenuBackGround.jpg");
    AbotProgrammTexture.loadFromFile("src/ImgMusFont/AboutProgramm.jpg");
    sf::Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), BackGround(menuBackTexture);
    sf::Sprite AbotProgramm(AbotProgrammTexture), back(backTexture);
    menu1.setPosition(350, 600); menu2.setPosition(325, 700); menu3.setPosition(375, 800); BackGround.setPosition(0, 0);
    AbotProgramm.setPosition(0, 0); back.setPosition(50, 1050);
    
    bool isMenu = true; int MenuNum = 0;

    while (isMenu)
    {
        menu1.setColor(sf::Color::White); menu2.setColor(sf::Color::White); menu3.setColor(sf::Color::White);

        MenuNum = 0; window.clear();

        if (sf::IntRect(350, 600, 550, 640).contains(sf::Mouse::getPosition(window))) 
        {menu1.setColor(sf::Color::Blue); menu2.setColor(sf::Color::White); menu3.setColor(sf::Color::White); MenuNum = 1;}
        if (sf::IntRect(325, 700, 570, 740).contains(sf::Mouse::getPosition(window))) 
        {menu2.setColor(sf::Color::Blue); menu1.setColor(sf::Color::White); menu3.setColor(sf::Color::White); MenuNum = 2;}
        if (sf::IntRect(350, 800, 470, 820).contains(sf::Mouse::getPosition(window))) 
        {menu3.setColor(sf::Color::Blue); menu2.setColor(sf::Color::White); menu1.setColor(sf::Color::White); MenuNum = 3;}
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (MenuNum == 1) {isMenu = false; return false;}     // старт
            if (MenuNum == 2) {isMenu = false;}                   // о программе
            if (MenuNum == 3) {window.close(); isMenu = false;}   // выход
            if (MenuNum == 4) {window.clear(); isMenu = true;}  // вернуться в меню
        }
   
        while (!isMenu && MenuNum == 2)
        {
            window.clear(); window.draw(AbotProgramm); window.draw(back); window.display();
            if (sf::IntRect(50, 1000, 150, 1100).contains(sf::Mouse::getPosition(window)) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {back.setColor(sf::Color(216,191,216)); MenuNum = 0; isMenu = true;}
        }

    window.draw(BackGround); window.draw(menu1); window.draw(menu2); window.draw(menu3); window.display();
    }
    return true;
}
