/*****************************************************************
 * Filename: cup_handling_nodes.h                                *
 * Description: Contains custom behavior tree nodes related to   *
 *              handling a cup.                                  *
 *****************************************************************/

#pragma once

#include <iostream>
#include <chrono>
#include "behaviortree_cpp/action_node.h"
#include "behaviortree_cpp/bt_factory.h"

using namespace std::chrono_literals;

/*****************************************************************
 * Class: ApproachCup                                            *
 *                                                               *
 * Description: This class represents a custom behavior tree     *
 *              action node that simulates approaching a cup.    *
 *****************************************************************/
class ApproachCup : public BT::SyncActionNode
{
public:
  // Constructor
  explicit ApproachCup(const std::string &name) : BT::SyncActionNode(name, {})
  {
  }

  // Function: tick
  // Description: Executes the approach cup action.
  // Returns: The status of the action (SUCCESS, FAILURE, RUNNING).
  BT::NodeStatus tick() override
  {
    std::cout << "Approach Cup: " << this->name() << std::endl;

    // Simulate the time it takes to approach the cup (5 seconds).
    std::this_thread::sleep_for(5s);

    return BT::NodeStatus::SUCCESS;
  }
};

/*****************************************************************
 * Function: LocateCup                                           *
 *                                                               *
 * Description: Simulates locating the cup and returns           *
 *              the node status as SUCCESS.                      *
 *****************************************************************/
BT::NodeStatus LocateCup()
{
  std::cout << "Cup Located!" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

/*****************************************************************
 * Class: GripperInterface                                       *
 *                                                               *
 * Description: This class represents a gripper interface and    *
 *              provides open and close functionalities.         *
 *****************************************************************/
class GripperInterface
{
public:
  // Constructor
  GripperInterface() : gripper_opened(true) {}

  // Function: open
  // Description: Simulates opening the gripper.
  // Returns: The status of the action (SUCCESS).
  BT::NodeStatus open()
  {
    gripper_opened = true;
    std::cout << "Gripper opened" << std::endl;
    return BT::NodeStatus::SUCCESS;
  }

  // Function: close
  // Description: Simulates closing the gripper.
  // Returns: The status of the action (SUCCESS).
  BT::NodeStatus close()
  {
    gripper_opened = false;
    std::cout << "Gripper closed" << std::endl;
    return BT::NodeStatus::SUCCESS;
  }

private:
  bool gripper_opened; // Holds the status of the gripper (open/closed).
};

/*****************************************************************
 * Class: RetrieveCup                                            *
 *                                                               *
 * Description: This class represents a custom behavior tree     *
 *              action node that simulates retrieving a cup.     *
 *****************************************************************/
class RetrieveCup : public BT::SyncActionNode
{
public:
  // Constructor
  explicit RetrieveCup(const std::string &name) : BT::SyncActionNode(name, {})
  {
  }

  // Function: tick
  // Description: Executes the retrieve cup action.
  // Returns: The status of the action (SUCCESS, FAILURE, RUNNING).
  BT::NodeStatus tick() override
  {
    std::cout << "Retrieved Cup: " << this->name() << std::endl;

    // Simulate the time it takes to retrieve the cup (3 seconds).
    std::this_thread::sleep_for(3s);

    return BT::NodeStatus::SUCCESS;
  }
};
