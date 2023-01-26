#include "route_planner.h"
#include <algorithm>
#include <iostream>

RoutePlanner::RoutePlanner(RouteModel& model, float start_x, float start_y, float end_x, float end_y): m_Model(model) {
  // Convert inputs to percentage:
  start_x *= 0.01;
  start_y *= 0.01;
  end_x *= 0.01;
  end_y *= 0.01;

  this->start_node = &this->m_Model.FindClosestNode(start_x, start_y);
  this->end_node = &this->m_Model.FindClosestNode(end_x, end_y);

}

float RoutePlanner::CalculateHValue(RouteModel::Node const* node) {
  return node->distance(*this->end_node);
}

void RoutePlanner::AddNeighbors(RouteModel::Node* current_node) {
  current_node->FindNeighbors();
  for (auto& next_node : current_node->neighbors) {
    next_node->parent = current_node;
    next_node->g_value = current_node->g_value + current_node->distance(*next_node);
    next_node->h_value = CalculateHValue(next_node);
    next_node->visited = true;
    this->open_list.push_back(next_node);
  }
}

RouteModel::Node* RoutePlanner::NextNode() {
  std::sort(this->open_list.begin(), this->open_list.end(), [](auto a, auto b) {
    return (a->g_value + a->h_value) > (b->g_value + b->h_value);
    });

  auto lowest_sum = this->open_list.back();
  this->open_list.pop_back();
  return lowest_sum;
}

std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node* current_node) {
  distance = 0.0f;
  std::vector<RouteModel::Node> path_found;


  while (current_node != start_node) {
    distance += current_node->distance(*current_node->parent);
    path_found.push_back(*current_node);
    current_node = current_node->parent;
  }

  path_found.push_back(*current_node); // Add the start_node to the path vector.
  std::reverse(path_found.begin(), path_found.end());

  distance *= m_Model.MetricScale(); // Multiply the distance by the scale of the map to get meters.
  return path_found;

}

void RoutePlanner::AStarSearch() {
  RouteModel::Node* current_node = nullptr;

  current_node = start_node;
  current_node->visited = true;
  AddNeighbors(current_node);

  while (!this->open_list.empty()) {
    current_node = NextNode();

    if (current_node == end_node) {
      m_Model.path = ConstructFinalPath(current_node);
      return;
    }

    AddNeighbors(current_node);
  }
}