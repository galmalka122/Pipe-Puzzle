#pragma once
#include <string>
#include <map>
#include <array>

const std::string STAGES_FILE = "Stages.txt";
const int WINDOW_HEIGHT = 1000;
const int WINDOW_WIDTH = 1000;
const int BOARD_WIDTH = WINDOW_WIDTH * 0.8;
const int BOARD_HEIGHT = WINDOW_HEIGHT * 0.8;
const int NUM_OF_TEXTURES = 6;
const int SIDES = 4;
const int DEGREE = 90;

enum Textures_t {SOURCE_F, SINK_E, STRAIGHT_E, CURVED_E, T_E, PLUS_E, NON};

//Pipe type
const char SOURCE = 's';
const char STRAIGHT = '-';
const char CURVED = '(';
const char T = 'T';
const char PLUS = '+';
const char SINK = 'd';

//Pipe sides
const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

//Start position
const std::array<bool, SIDES> SOURCE_SINK_DIRECTION = {false, true, false, false};
const std::array<bool, SIDES> STRAIGHT_DIRECTION = {false, false, true, true};
const std::array<bool, SIDES> CURVED_DIRECTION = {false, true, false, true};
const std::array<bool, SIDES> T_DIRECTION = {false, true, true, true};
const std::array<bool, SIDES> PLUS_DIRECTION = {true, true, true, true};