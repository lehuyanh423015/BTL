#ifndef DEFS_H
#define DEFS_H

#include <SDL.h>
#include <SDL_image.h>

#define SCREEN_WIDTH 955
#define SCREEN_HEIGHT 560
#define WINDOW_TITLE "I'm so hungry!"

//image
#define BACKGROUND "img\\background.jpg"
#define PAUSE "img\\pause.png"
#define MENU "img\\menu.png"
#define DIED "img\\died.jpg"
#define G_PAUSE "img\\game_pause.jpg"
#define FISH_RIGHT "img\\right.png"
#define FISH_LEFT "img\\left.png"
#define FISH_DOWN "img\\down.png"
#define FISH_UP "img\\up.png"

//font
#define FONT "font\\DancingScript-Bold.ttf"

//sound
#define MUSIC "sound\\music.mp3"
#define BITE_WAV "sound\\bite.wav"

const int RIGHT_CLIPS[][4] = {
    {  0, 12, 36, 36},
    { 48, 12, 36, 36},
    { 98, 12, 36, 36},
    {155, 12, 36, 36},
    {204, 12, 36, 36},
    {248, 12, 36, 36}};
const int FRAMES = sizeof(RIGHT_CLIPS)/sizeof(int)/4;

const int LEFT_CLIPS[][4] = {
    {  4, 12, 36, 36},
    { 48, 12, 36, 36},
    { 97, 12, 36, 36},
    {154, 12, 36, 36},
    {204, 12, 36, 36},
    {252, 12, 36, 36}};

const int DOWN_CLIPS[][4] = {
    {0,   0, 36, 36},
    {0,  48, 36, 36},
    {0,  98, 36, 36},
    {0, 155, 36, 36},
    {0, 204, 36, 36},
    {0, 248, 36, 36}};

const int UP_CLIPS[][4] = {
    {12, 252, 36, 36},
    {12, 204, 36, 36},
    {12, 154, 36, 36},
    {12,  97, 36, 36},
    {12,  48, 36, 36},
    {12,   4, 36, 36}};


#endif
