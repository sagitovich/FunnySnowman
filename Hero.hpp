#include <SFML/Graphics.hpp>

class Hero
{
    private:
        int m_WindowX; int m_WindowY;
    public:
        sf::Sprite m_HeroSprite;                        // создание спрайта
        sf::Texture m_HeroTexture;                      // создание текстуры
        sf::Vector2u m_HeroSize;
        sf::Vector2f Posi;
        int m_HLine; // позиция героя

        void setWin(int WinX, int WinY) {m_WindowX = WinX; m_WindowY = WinY;}

        Hero(sf::Sprite HeroSprite)   {m_HeroSprite = HeroSprite;}
        Hero(sf::Texture HeroTexture) {m_HeroTexture = HeroTexture;}

        void setHero()
        {
            m_HeroTexture.loadFromFile("src/ImgMusFont/snow.png");    // загрузка картинки
            m_HeroSize = m_HeroTexture.getSize();
            m_HeroSprite.setTexture(m_HeroTexture);             // присвоение текстуры спрайту 
        }

        void setPos(int HeroPos)
        {
            m_HLine = HeroPos;
            switch (m_HLine)
            {
            case 1: {
                sf::Vector2f m_Position1(m_WindowX/3 - m_HeroSize.x, m_WindowY - m_HeroSize.y - 75);
                m_HeroSprite.setPosition(m_Position1.x, m_Position1.y);
                break;}
            
            case 2: {
                sf::Vector2f m_Position2(m_WindowX/2 - m_HeroSize.x/2, m_WindowY - m_HeroSize.y - 75);
                m_HeroSprite.setPosition(m_Position2.x, m_Position2.y);
                break;}

            case 3: {
                sf::Vector2f m_Position3(m_WindowX/3 + 1.075*m_HeroSize.x, m_WindowY - m_HeroSize.y - 75);
                m_HeroSprite.setPosition(m_Position3.x, m_Position3.y);
                break;}
            }
        }

        sf::Vector2f getPos(int N) // N - отвечает за номер кейса
        {
            sf::Vector2f Position1(m_WindowX/3 - m_HeroSize.x, m_WindowY - m_HeroSize.y - 75);
            sf::Vector2f Position2(m_WindowX/2 - m_HeroSize.x/2, m_WindowY - m_HeroSize.y - 75);
            sf::Vector2f Position3(m_WindowX/3 + 1.075*m_HeroSize.x, m_WindowY - m_HeroSize.y - 75);
            switch (N)
            {
                case 1: {return Position1;}
                case 2: {return Position2;}
                case 3: {return Position3;}
            }
            return Posi;
        }
};
