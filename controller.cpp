#include "controller.h"

Controller::Controller(Maze &maze, Mouse *mouse, Logger<std::string> &logger, mazeGeneratorPrim *mazeGenerator)
    : maze(maze), mouse(mouse), logger(logger), exploring(false), elapsedTime(0) {
    this->mazeGen = mazeGenerator;
}

void Controller::startSimulation() {
    changePhase(SimulationState::Exploring);
    resetData();
}

void Controller::stopSimulation() {
    changePhase(SimulationState::NotStarted);
    resetData();
}

void Controller::updateMaze() {
    Maze newMaze = Maze(maze.getMazeLayout().size(), maze.getMazeLayout()[0].size());
    maze.uploadMazeLayout(newMaze.getMazeLayout());
    mazeGen->generate(maze);
    mouse->reset();
}

void Controller::updateTimer() {
    elapsedTime++;
}

void Controller::resetData() {
    elapsedTime = 0;
    mazeGen->generate(maze, true);
    mouse->reset();
}

bool Controller::isExploring() const {
    return exploring;
}

int Controller::getElapsedTime() const {
    return elapsedTime;
}

Position Controller::getMousePosition() const {
    return mouse->getPosition();
}

void Controller::changePhase(SimulationState newState) {
    switch (newState) {
        case SimulationState::NotStarted:
            exploring = false;
            break;
        case SimulationState::Exploring:
            exploring = true;
            break;
        case SimulationState::Returning:
            break;
        case SimulationState::Running:
            break;
        case SimulationState::Finished:
            exploring = false;
            break;
    }
}

std::vector<std::vector<int>> Controller::getMazeLayout() const {
    return maze.getMazeLayout();
}

Position Controller::getMazeDestination() const {
    return maze.getDestination();
}
