#include "UI.hpp"
#include "Render.hpp"

Settings settings;

int main()
{
    // Non-SFML init
    Restart();
    srand(time(0));
    settings.Load("settings.txt");
    Render();

    // SFML init
    sf::RenderWindow window(sf::VideoMode({windowSize[0], windowSize[1]}), "3DRenderer");
    window.setFramerateLimit(0);
    sf::Font font("assets/JetBrainsMonoNerdFont-Medium.ttf");
    sf::Text FPS(font);
    if (verticalSync)
        window.setVerticalSyncEnabled(true);
    else
        window.setVerticalSyncEnabled(false);
    
    // ImGUI init
    (void) ImGui::SFML::Init(window);
    
    sf::Clock deltaTimeClock;
    sf::Time deltaTime;
    sf::Clock delayClock;
    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window, *event);
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear();
        deltaTime = deltaTimeClock.restart();
        ImGui::SFML::Update(window, deltaTime);
        
        // Draw ImGUI GUI
        ShowMenuBar();
        if (isSettings) ShowSettings(&isSettings);

        if (delayClock.getElapsedTime().asSeconds() > 0.5)
        {
            delayClock.restart();
            
            FPS.setString("FPS: " + std::to_string((int)(1 / deltaTime.asSeconds())));
            if (lastVSync != verticalSync)
            {
                lastVSync = verticalSync;
                if (verticalSync)
                    window.setVerticalSyncEnabled(true);
                else
                    window.setVerticalSyncEnabled(false);        
            }
        }

        // Draw FPS
        FPS.setPosition({0, menuOffset * 1.f});
        FPS.setCharacterSize(24);
        window.draw(FPS);

        ImGui::SFML::Render(window);
        window.display();
    }

    settings.Save("settings.txt");
    ImGui::SFML::Shutdown();
}

