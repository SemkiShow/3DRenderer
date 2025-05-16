#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <random>

extern int menuOffset;

extern bool isSettings;
extern bool lastVSync;

extern unsigned int windowSize[2];

void ShowSettings(bool* isOpen);
void Restart();
void ShowMenuBar();
void InitUI(sf::RenderWindow* window);
void DrawUI(sf::RenderWindow* window);
