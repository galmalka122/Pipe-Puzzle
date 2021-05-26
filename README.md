Implementation of the game "Pipe" using SFML (Grapich library)

Made by:

    Dvir Meir Perkin
    Gal Meir Malka
    Yaniv Sonino

General Description:

    This program is an implementation of the game pipe.

Game Instructions:
    The user needs to connect all the sinks to the water.
    The user can rotate each pipe (except the sinks) using the left and right click.
    Right click for rotate in -90 degree and left for rotate in 90 degree.

Design:

    The game contain several objects:
    GameBoard - The main object of the game that represent the game board, reads each level and
	            manage the actions on the board.
    Pipe - Connect or disconnect to other pipes, can stream water and rotate.
    StageDetails - Represent the number of the current stage and the 
                   number of clicks that take to the player to solve the current stage.

Files list:
    main.cpp - Plays the game and handle exceptions.
    GameController.h, GameController.cpp - A class that manage the game and
                                           controls the interaction between the objects in the game.
    GameBoard.h, GameBoard.cpp - A class that represent a game board.
    StageDetails.h, StageDetails.cpp - A class that represent all the stage details.
    Pipe.h, Pipe.cpp - A class that represent a pipe.
    Graph.h, Graph.cpp - A template class that implement a graph and specialization classes of graph.
    File.h, File.cpp - A class that represent a file.
    FileError.h - A class that represent file exception.
    Font.h , Font.cpp - A singleton class that responsible for the font that used in the game screens.
    Sound.h , Sound.cpp - A singleton class that responsible for all the sounds in the game.
    Textures.h , Textures.cpp - A singleton class that responsible for all the textures that used in the game.
    Macros.h - A file that includes all the constant variables in the program.

Stages:

    The stages of the game are represent in Stages.txt file.
    To build a new stage the user need to indicate the size and the requested pipes with the following character:

    's' - Source pipe.
    'd' - Sink pipe.
    '-' - Straight pipe.
    '(' - Curved pipe.
    'T' - T shape pipe.
    '+' - Cross pipe.
    'x' - Blank space.

    Next to each character the user need to indicate the direction of the pipe (Represented in degrees).
    The direction need to divide by 90.

    Example:
    2 2 -> Indicate the width and the height of the board.
    s 90 -> Indicate source pipe and rotate it in 90 degree to the left.
    - 0
    ( 90
    d 270

    Between each two stages the user must leave one blank line.

Main data structures and their role:
    using boardPosition = std::pair<int, int> - Indicates the indexes of each pipe in the game board.
    std::vector<std::vector<std::unique_ptr<Pipe>>> m_pipeSys - Holds all the pipes objects in each stage.
    std::vector<boardPosition> m_sources - Holds all the source in each stage.
    std::map<T,std::list<T>> m_neighborsList - Data structure in graph that holds each node in the graph
                                               and the neighbors lists.
    std::array<bool, SIDES> m_direction - Indicates the pipe direction.



Worth Notes Algorithms:

    BFS - A graph algorithm to find all shortest path from given source node.
    It gets each water source and returns all neighbors which helps to determine if the
    destination nodes (sink) is connected.

Known bugs (in development):

    None

Other Comments:

    We chose std::map data structure for the graph algorithm to minimize the run time of the algorithm
    and because it is the easier way to represent a node and it's neighbors list, In addition we didn't chose
    unordered_map DS because we use a non primitive parameter for the keys.

    We chose std::list to represent the neighbors lists because this std::list is not a continuous memory
    and does not require unnecessary memory.

    We chose std::vector data structure for holding the pipes in each stage because this is the most convenient
    way to work on a matrix board.

    We chose std::array to represent the direction of the pipe because this is a static array that allows multiple
    actions that a regular array didn't allow.

    We chose std::pair to represent the indexes of each pipe because this is a convenient and clean way to hold two integers.

    std::count_if - Used for check if the user connect all the sinks to a water sources.