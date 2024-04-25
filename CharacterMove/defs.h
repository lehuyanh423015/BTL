#ifndef _DEFS__H
#define _DEFS__H

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "Hello World!";

const char* FISH_RIGHT  = "img\\right.png";
const int RIGHT_CLIPS[][4] = {
    {  0, 12, 36, 36},
    { 48, 12, 36, 36},
    { 98, 12, 36, 36},
    {155, 12, 36, 36},
    {204, 12, 36, 36},
    {248, 12, 36, 36}};
const int FRAMES = sizeof(RIGHT_CLIPS)/sizeof(int)/4;

const char* FISH_LEFT = "img\\left.png";
const int LEFT_CLIPS[][4] = {
    {  4, 12, 36, 36},
    { 48, 12, 36, 36},
    { 97, 12, 36, 36},
    {154, 12, 36, 36},
    {204, 12, 36, 36},
    {252, 12, 36, 36}};

const char* FISH_DOWN = "img\\down.png";
const int DOWN_CLIPS[][4] = {
    {0,   0, 36, 36},
    {0,  48, 36, 36},
    {0,  98, 36, 36},
    {0, 155, 36, 36},
    {0, 204, 36, 36},
    {0, 248, 36, 36}};

const char* FISH_UP = "img\\up.png";
const int UP_CLIPS[][4] = {
    {12, 252, 36, 36},
    {12, 204, 36, 36},
    {12, 154, 36, 36},
    {12,  97, 36, 36},
    {12,  48, 36, 36},
    {12,   4, 36, 36}};

#endif
