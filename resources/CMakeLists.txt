configure_file (C:/SFML/SFML-2.5.1/bin/openal32.dll ${CMAKE_BINARY_DIR} COPYONLY)

# Stages file.
configure_file ("Stages.txt" ${CMAKE_BINARY_DIR} COPYONLY)

# Font.
configure_file ("Impact.ttf" ${CMAKE_BINARY_DIR} COPYONLY)

# Sprites.
configure_file ("BackGround.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("WinScreen.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("LevelUP.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("Source.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("Sink_E.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("Sink_F.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("Straight_E.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("Straight_F.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("Curved_E.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("Curved_F.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("T_Pipe_E.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("T_Pipe_F.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("Plus_E.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("Plus_F.png" ${CMAKE_BINARY_DIR} COPYONLY)

# Sounds
configure_file ("WinSound.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("Click.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("LevelUP.wav" ${CMAKE_BINARY_DIR} COPYONLY)