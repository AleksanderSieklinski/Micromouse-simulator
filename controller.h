#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "maze.h"
#include "mouse.h"
#include "logger.h"
#include "mazegeneratorprim.h"

/**
* @brief Enum class for the state of the simulation
*
* This enum class is used to represent the state of the simulation.
* The simulation can be in one of the following states: NotStarted, Exploring, Returning, Running, Finished.
*/
enum class SimulationState {
    NotStarted,
    Exploring,
    Returning,
    Running,
    Finished
};

class Controller {
public:
    /**
    * @brief Constructor for Controller.
    * @param maze The maze to be controlled.
    * @param mouse The mouse object to be controlled.
    * @param logger The logger object for logging data.
    */
    Controller(Maze &maze, Mouse *mouse, Logger<std::string> &logger, mazeGeneratorPrim *mazeGenerator);

    /**
    * @brief Starts the simulation.
    * @details This function initializes the simulation and resets the data.
    */
    void startSimulation();
    /**
    * @brief Stops the simulation.
    * @details This function stops the simulation and resets the data.
    */
    void stopSimulation();
    /**
    * @brief Updates the maze layout.
    * @details This function updates the maze layout and resets the mouse position.
    */
    void updateMaze();
    /**
    * @brief Updates the timer for the simulation.
    * @details This function increments the elapsed time for the simulation.
    */
    void updateTimer();
    /**
    * @brief Resets the data for the simulation.
    * @details This function resets the elapsed time and maze layout.
    */
    void resetData();
    /**
    * @brief Gets the current state of the simulation.
    * @return The current state of the simulation.
    */
    SimulationState getCurrentState() const;
    /**
    * @brief Checks if the mouse is exploring the maze.
    * @return True if the mouse is exploring the maze, false otherwise.
    */
    bool isExploring() const;
    /**
    * @brief Gets the elapsed time for the simulation.
    * @return The elapsed time for the simulation.
    */
    int getElapsedTime() const;
    /**
    * @brief Gets the current position of the mouse.
    * @return The current position of the mouse.
    */
    Position getMousePosition() const;
    /**
    * @brief Gets the maze layout.
    * @return The maze layout as a 2D vector.
    */
    std::vector<std::vector<int>> getMazeLayout() const;
    /**
    * @brief Gets the destination position in the maze.
    * @return The destination position in the maze.
    */
    Position getMazeDestination() const;
    /**
    * @brief Changes the phase of the simulation.
    * @param newState The new state of the simulation.
    * @details This function changes the state of the simulation to the new state.
    */
    void changePhase(SimulationState newState);

private:
    Maze &maze; ///< The maze object to be controlled.
    Mouse *mouse; ///< The mouse object to be controlled.
    Logger<std::string> &logger; ///< The logger object for logging data.
    mazeGeneratorPrim *mazeGen; ///< The maze generator object.
    bool exploring; ///< Flag indicating if the mouse is exploring the maze.
    int elapsedTime; ///< The elapsed time for the simulation.
};

#endif // CONTROLLER_H
