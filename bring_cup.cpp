/*****************************************************************
 * Filename: main.cpp                                            *
 * Description: The main source file that creates and executes   *
 *              a behavior tree to bring a cup using custom      *
 *              behavior tree nodes.                             *
 *****************************************************************/

#include <iostream>
#include "behaviortree_cpp/action_node.h"
#include "behaviortree_cpp/bt_factory.h"
#include "bring_cup.h" // Include the header file with custom nodes

int main()
{
  // Create a BehaviorTreeFactory to register custom nodes and conditions
  BT::BehaviorTreeFactory factory;

  // Register the simple condition "LocateCup" with the LocateCup function
  factory.registerSimpleCondition("LocateCup", std::bind(LocateCup));

  // Register the custom node "ApproachCup" of type ApproachCup
  factory.registerNodeType<ApproachCup>("ApproachCup");

  // Create a GripperInterface object to use its member functions in the behavior tree
  GripperInterface gripper;

  // Register the simple action "OpenGripper" with the GripperInterface's open() function
  factory.registerSimpleAction(
      "OpenGripper",
      std::bind(&GripperInterface::open, &gripper));

  // Register the simple action "CloseGripper" with the GripperInterface's close() function
  factory.registerSimpleAction(
      "CloseGripper",
      std::bind(&GripperInterface::close, &gripper));

  // Register the custom node "RetrieveCup" of type RetrieveCup
  factory.registerNodeType<RetrieveCup>("RetrieveCup");

  // Create the behavior tree by loading it from a file named "bring_cup_tree.xml"
  auto tree = factory.createTreeFromFile("./../bring_cup_tree.xml");

  // Execute the behavior tree until it finishes running
  tree.tickWhileRunning();

  return 0;
}
