#include "control.hpp"

std::vector<unsigned char> keyPresses;

void keyboardDownEvent(unsigned char key, int x, int y)
{
    for(unsigned char k : keyPresses)
    {
        if(k == key)
        {
            return;
        }
    }

    keyPresses.push_back(key);
}

void keyboardUpEvent(unsigned char key, int x, int y)
{
    for(size_t i = 0; i<key; i++)
    {
        if(keyPresses[i] == key)
        {
            keyPresses.erase(keyPresses.begin() + i);
            break;
        }
    }
}

void mouseClickEvent(int b, int s, int x, int y)
{
}

void mouseMoveEvent(int x, int y)
{
}

void mouseDragEvent(int x, int y)
{
}