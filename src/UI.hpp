#include "imgui.h"
#include "imgui-SFML.h"
#include "Constants.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>
#include <algorithm>

extern int menuOffset;
extern bool verticalSync;

extern bool isSettings;
extern bool lastVSync;
    
class Settings
{
    public:
        void Save(std::string fileName);
        void Load(std::string fileName);
};

void ShowSettings(bool* isOpen);
void Restart();
void ShowMenuBar();
void InitUI(sf::RenderWindow* window);
void DrawUI(sf::RenderWindow* window);
