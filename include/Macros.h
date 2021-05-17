#pragma once
#include <string>

const std::string STAGES_FILE = "Stages.txt";
const int WINDOW_HEIGHT = 1000;
const int WINDOW_WIDTH = 1000;
const int BOARD_WIDTH = WINDOW_WIDTH * 0.8;
const int BOARD_HEIGHT = WINDOW_HEIGHT * 0.8;
const int NUM_OF_TEXTURES = 6;
const int SIDES = 4;

enum Textures_t {SOURCE_F, SINK_E, STRAIGHT_E, CURVED_E, T_E, PLUS_E, NON};

//Pipe type
const char SOURCE = 's';
const char PIPE = 'p';
const char SINK = 'd';

//Pipe sides
const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

//Pipes
enum PipeType_t {SOURCE_SINK_UP_P, SOURCE_SINK_DOWN_P, SOURCE_SINK_LEFT_P, SOURCE_SINK_RIGHT_P,
                STRAIGHT_HORIZONTAL_P, STRAIGHT_VERTICAL_P,
                CURVED_UP_LEFT_P, CURVED_UP_RIGHT_P, CURVED_DOWN_LEFT_P, CURVED_DOWN_RIGHT_P,
                T_UP_P, T_DOWN_P, T_LEFT_P, T_RIGHT_P,
                PLUS_P};

const std::unordered_map<std::string, PipeType_t> PIPES = {{"0001" , SOURCE_SINK_RIGHT_P}, {"0010" , SOURCE_SINK_LEFT_P},
                                                           {"0011" , STRAIGHT_HORIZONTAL_P}, {"0100" , SOURCE_SINK_DOWN_P},
                                                           {"0101" , CURVED_DOWN_RIGHT_P}, {"0110" , CURVED_DOWN_LEFT_P},
                                                           {"0111" , T_DOWN_P}, {"1000" , SOURCE_SINK_UP_P},
                                                           {"1001" , CURVED_UP_RIGHT_P}, {"1010" , CURVED_UP_LEFT_P},
                                                           {"1011" , T_UP_P}, {"1100" , STRAIGHT_VERTICAL_P},
                                                           {"1101" , T_RIGHT_P}, {"1110" , T_LEFT_P},
                                                           {"1111" , PLUS_P}};

//Start position
const std::array<bool, SIDES> SOURCE_SINK_DIRECTION = {false, true, false, false};
const std::array<bool, SIDES> STRAIGHT_DIRECTION = {false, false, true, true};
const std::array<bool, SIDES> CURVED_DIRECTION = {false, true, false, true};
const std::array<bool, SIDES> T_DIRECTION = {false, true, true, true};
const std::array<bool, SIDES> PLUS_DIRECTION = {true, true, true, true};