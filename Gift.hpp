#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Gift
{
    private:
        int m_WindowX, m_WindowY;                        // размеры окна
    public:
        double m_Vy;                                     // скорость подарка
        int m_GLine;                                     // линия подарка
        sf::Sprite m_GiftSprite;                         // создание спрайта
        sf::Texture m_GiftTexture;                       // создание текстуры
        sf::Vector2u m_GiftSize;                         // размеры подарка
        sf::Vector2f m_GiftPosition;                     // текущая позиция

        void setWin(int WinX, int WinY) {m_WindowX = WinX; m_WindowY = WinY;}
        Gift(sf::Sprite GiftSprite)    {m_GiftSprite = GiftSprite;}
        Gift(sf::Texture GiftTexture)  {m_GiftTexture = GiftTexture;}

        void setTempPosition(float x, float y) {m_GiftPosition.x = x; m_GiftPosition.y = y;}

        void SetGift(int GiftPos, double Vy)  
        {   
            m_Vy = Vy; m_GLine = GiftPos;
            m_GiftTexture.loadFromFile("src/ImgMusFont/gift.png");       // загрузка картинки
            m_GiftSprite.setTexture(m_GiftTexture);              // присвоение картинки 
            
            m_GiftSize = m_GiftTexture.getSize();           
            sf::Vector2f TPosition1(m_WindowX/4 - m_GiftSize.x, float(m_GiftSize.y) * (-2));    // начальные координаты 1 линии
            sf::Vector2f TPosition2(m_WindowX/2 - m_GiftSize.x/2, float(m_GiftSize.y) * (-2));  // начальные координаты 2 линии
            sf::Vector2f TPosition3(m_WindowX - 1.9*m_GiftSize.x, float(m_GiftSize.y) * (-2));  // начальные координаты 3 линии
                     
            switch(m_GLine)
            {
            case 1: {m_GiftPosition = TPosition1; break;}   // придать подарку 1 начальные координаты
            case 2: {m_GiftPosition = TPosition2; break;}   // придать подарку 2 начальные координаты
            case 3: {m_GiftPosition = TPosition3; break;}   // придать подарку 3 начальные координаты
            }
        }
        
        void MoveGift(Hero object, int &GiftPoint, int &GiftLose)
        {
            sf::Vector2f tpos1(m_WindowX/4 - m_GiftSize.x, -300);     
            sf::Vector2f tpos2(m_WindowX/2 - m_GiftSize.x/2, -300);       
            sf::Vector2f tpos3(m_WindowX - 1.9*m_GiftSize.x, -300);       
            
            switch (m_GLine)
            {
            case 1: {
                if (m_GiftPosition.y < m_WindowY)   // движение подарка
                {   
                    setTempPosition(m_GiftPosition.x, m_GiftPosition.y );
                    m_GiftSprite.setPosition(m_GiftPosition.x, m_GiftPosition.y += m_Vy);
                }
                if ((m_GiftPosition.y >= m_WindowY - object.m_HeroSize.y - m_GiftSize.y - 55) && (m_GLine == object.m_HLine))    // граница героя
                {
                    GiftPoint += 1;
                    m_GiftPosition.y = tpos1.y;
                    setTempPosition(m_GiftPosition.x, -300);
                    m_GiftSprite.setPosition(m_GiftPosition.x, -300 + m_Vy);
                }
                if (m_GiftPosition.y >= m_WindowY)  // граница экрана
                {   
                    GiftLose += 1;
                    m_GiftPosition.y = tpos1.y; 
                    setTempPosition(m_GiftPosition.x, -300);
                    m_GiftSprite.setPosition(m_GiftPosition.x, -300 + m_Vy);
                }
                break;}
            case 2: {
                if (m_GiftPosition.y < m_WindowY)   // движение подарка
                {   
                    setTempPosition(m_GiftPosition.x, m_GiftPosition.y );
                    m_GiftSprite.setPosition(m_GiftPosition.x, m_GiftPosition.y += m_Vy);
                }
                if (m_GiftPosition.y >= m_WindowY)  // граница экрана
                {   
                    GiftLose += 1;
                    m_GiftPosition.y = tpos2.y; 
                    setTempPosition(m_GiftPosition.x, -300);
                    m_GiftSprite.setPosition(m_GiftPosition.x, -300 + m_Vy);
                }
                if ((m_GiftPosition.y >= m_WindowY - object.m_HeroSize.y - m_GiftSize.y - 75) && (m_GLine == object.m_HLine))    // граница героя
                {
                    GiftPoint += 1;
                    m_GiftPosition.y = tpos2.y;
                    setTempPosition(m_GiftPosition.x, -300);
                    m_GiftSprite.setPosition(m_GiftPosition.x, -300 + m_Vy);
                }
                break;}
            case 3: {
                if (m_GiftPosition.y < m_WindowY)   // движение подарка
                {   
                    setTempPosition(m_GiftPosition.x, m_GiftPosition.y );
                    m_GiftSprite.setPosition(m_GiftPosition.x, m_GiftPosition.y += m_Vy);
                }
                if (m_GiftPosition.y >= m_WindowY)  // граница экрана
                {   
                    GiftLose += 1;
                    m_GiftPosition.y = tpos3.y; 
                    setTempPosition(m_GiftPosition.x, -300);
                    m_GiftSprite.setPosition(m_GiftPosition.x, -300 + m_Vy);
                }
                if ((m_GiftPosition.y >= m_WindowY - object.m_HeroSize.y - m_GiftSize.y - 65) && (m_GLine == object.m_HLine))    // граница героя
                {
                    GiftPoint += 1;
                    m_GiftPosition.y = tpos3.y;
                    setTempPosition(m_GiftPosition.x, -300);
                    m_GiftSprite.setPosition(m_GiftPosition.x, -300 + m_Vy);
                }
                break;}
            }
        }
};

