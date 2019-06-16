#ifndef CONTROL_HPP
#define CONTROL_HPP

#include <iostream>
#include <vector>

std::vector<unsigned char> keyPresses;

void keyboardDownEvent(unsigned char, int, int);
void keyboardUpEvent(unsigned char, int, int);

void mouseClickEvent(int, int, int, int);
void mouseMoveEvent(int, int);
void mouseDragEvent(int, int);

#endif