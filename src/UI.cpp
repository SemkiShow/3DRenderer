#include "UI.hpp"
#include "Settings.hpp"

int menuOffset = 20;
unsigned int windowSize[2] = {16*50*2, 9*50*2};

bool isSettings = false;
bool lastVSync = verticalSync;

// SFML init
sf::Font font("assets/JetBrainsMonoNerdFont-Medium.ttf");
sf::Text FPS(font);
sf::Clock deltaTimeClock;
sf::Time deltaTime;
sf::Clock delayClock;

std::string* Split(std::string input, char delimiter = ' ')
{
    std::vector<std::string> output;
    output.push_back("");
    int index = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == delimiter)
        {
            index++;
            output.push_back("");
            continue;
        }
        output[index] += input[i];
    }
    std::string* outputArray = new std::string[output.size()];
    std::copy(output.begin(), output.end(), outputArray);
    return outputArray;
}

void ShowSettings(bool* isOpen)
{
    if (!ImGui::Begin("Settings", isOpen))
    {
        ImGui::End();
        return;
    }
    ImGui::Checkbox("vsync", &verticalSync);
    ImGui::End();
}

void Restart()
{
    
}

void ShowMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Menu"))
        {
            if (ImGui::MenuItem("Settings"))
            {
                isSettings = true;
                ShowSettings(&isSettings);
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
    return;
}

void InitUI(sf::RenderWindow* window)
{
    window->setFramerateLimit(0);
    if (verticalSync)
        window->setVerticalSyncEnabled(true);
    else
        window->setVerticalSyncEnabled(false);

    // ImGUI init
    (void) ImGui::SFML::Init(*window);
}

void DrawUI(sf::RenderWindow* window)
{
    while (const auto event = window->pollEvent())
    {
        ImGui::SFML::ProcessEvent(*window, *event);
        if (event->is<sf::Event::Closed>())
            window->close();
    }
    window->clear();
    deltaTime = deltaTimeClock.restart();
    ImGui::SFML::Update(*window, deltaTime);

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
                window->setVerticalSyncEnabled(true);
            else
                window->setVerticalSyncEnabled(false);        
        }
    }

    // Draw FPS
    FPS.setPosition({0, menuOffset * 1.f});
    FPS.setCharacterSize(24);
    window->draw(FPS);

    ImGui::SFML::Render(*window);
    window->display();
}
