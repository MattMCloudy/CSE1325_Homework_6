CC = g++
CXXFLAGS = `fltk-config --cxxflags`
LFLAGS = `fltk-config --ldflags`

all:
	$(CC) $(CXXFLAGS) Part/Arm.cpp Part/Battery.cpp Part/Head.cpp Part/Leg.cpp Part/Locomotor.cpp Part/Part.cpp Part/Torso.cpp Robot/Robot.cpp Factory/RobotFactory.cpp UI/CreateParts.cpp UI/ModelViewController.cpp main.cpp MainViewController.cpp $(LFLAGS) -lfltk_images -o Homework6
