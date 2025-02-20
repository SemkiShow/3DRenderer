#include "UI.hpp"
#include "Render.hpp"

Settings settings;

int main()
{
    // Non-SFML init
    Restart();
    srand(time(0));
    settings.Load("settings.txt");

    sf::RenderWindow window(sf::VideoMode({windowSize[0], windowSize[1]}), "3DRenderer");
    InitUI(&window);

    while (window.isOpen())
    {
        DrawUI(&window);
    }

    settings.Save("settings.txt");
    ImGui::SFML::Shutdown();
}

