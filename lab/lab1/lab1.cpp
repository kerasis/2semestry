#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "windows.h"


class AnimatedText
{
private:
    std::string m_text;
    int m_duration;
    int m_currentDuration = 0;

    void setText()
    {
        std::cout << "Enter your text: ";
        getline(std::cin, m_text);
        std::cout << "\n";
    }

    void setDuration(const std::string& m_text)
    {
        m_duration = (size(m_text));
    }

public:
    std::string* pt = &m_text;
    
    AnimatedText()
    {
        setText();
        setDuration(m_text);
    }

    void showString() const
    {
        std::cout << "Your text: " << m_text << std::endl;
    }

    void showDuration() const
    {
        std::cout << "Duration: " << m_duration << std::endl;
    }

    int getDurarion() const
    {
        return (m_duration);
    }

    std::string showElementOfText(std::string& m_text) 
    {
        m_currentDuration++;
        std::string curSymbol = m_text.substr(0,m_currentDuration);
        return curSymbol;     
    } 
};

int main()
{
    AnimatedText at;
    int duration = (at.getDurarion());
    at.showString();
    /*for (int i = 0; i < duration; i++)
    {
        std::cout << at.showElementOfText(*(at.pt));
    }*/

    sf::RenderWindow window(sf::VideoMode(500, 500), "AnimatedText", sf::Style::Close);
    sf::Event event;
        
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { window.close(); }
            sf::Text text;
            sf::Font font;
            font.loadFromFile("my_font.ttf");
            text.setFont(font);
            text.setCharacterSize(24);
            text.setColor(sf::Color::Magenta);
            text.setPosition(50, 10);

            for (int i = 0; i < (duration); i++)
            {
                text.setString((at.showElementOfText(*(at.pt))));
                window.draw(text);
                window.display();              
                Sleep(1000);
            }
            while (window.waitEvent(event))
            {
                if (event.type == sf::Event::Closed) { window.close(); }
            }
        }          
    }   
}
