#pragma once

#include <string>
#include <array>

const std::string STAGES_FILE = "Stages.txt";
const int WINDOW_HEIGHT = 1000;
const int WINDOW_WIDTH = 1000;
const int BOARD_OFFSET_HEIGHT = WINDOW_HEIGHT / 10;
const int BOARD_OFFSET_WIDTH = WINDOW_WIDTH / 10;
const int BOARD_HEIGHT = WINDOW_HEIGHT * 0.8;
const int BOARD_WIDTH = WINDOW_WIDTH * 0.8;
const int NUM_OF_TEXTURES = 14;
const int WIN_SCREEN_PAUSE = 5;
const int CHARACTER_SIZE = 50;
const int LEVEL_UP_PAUSE = 4;
const int NUM_OF_SOUNDS = 3;
const int DEGREE = 90;
const int VOLUME = 20;
const int SIDES = 4;


enum Textures_t {BACKGROUND, WIN_SCREEN, LEVEL_UP, SOURCE_F, SINK_E, SINK_F, STRAIGHT_E, STRAIGHT_F,
                CURVED_E, CURVED_F, T_E, T_F, PLUS_E, PLUS_F};

enum Sounds_t {WIN_SOUND, CLICK_SOUND, LEVEL_UP_SOUND};

//Pipe type
const char SOURCE = 's';
const char STRAIGHT = '-';
const char CURVED = '(';
const char T = 'T';
const char PLUS = '+';
const char SINK = 'd';
const char NON_PIPE = 'x';

//Pipe sides
const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

//Start position
const std::array<bool, SIDES> SOURCE_SINK_DIRECTION = {false, true, false, false};
const std::array<bool, SIDES> STRAIGHT_DIRECTION = {true, true, false, false};
const std::array<bool, SIDES> CURVED_DIRECTION = {false, true, false, true};
const std::array<bool, SIDES> T_DIRECTION = {false, true, true, true};
const std::array<bool, SIDES> PLUS_DIRECTION = {true, true, true, true};