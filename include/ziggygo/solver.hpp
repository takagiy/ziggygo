// Copyright (c) TakagiY 2019
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_SOLVER
#define COM_GITHUB_TAKAGIY_ZIGGYGO_SOLVER

#include "./cart.hpp"
#include "./declare.hpp"
#include "./line.hpp"
#include "./node.hpp"
#include "./path.hpp"
#include <deque>
#include <forward_list>
#include <map>
#include <queue>
#include <utility>
#include <vector>

namespace ziggygo {
  class solver {
    cart cart_;
    std::forward_list<line> walls_;
    std::deque<node> nodes_;
    std::map<point, node *, point_comparator> node_at;

    auto is_passible(const point &p, const point &q) const -> bool {
      for (auto &&wall : walls_) {
        if (line{p, q}.crosses(wall)) {
          return false;
        }
      }
      return true;
    }

    auto add_node_at(const point &p) -> void {
      if (node_at.count(p) != 0) {
        return;
      }
      nodes_.push_back(node{p});
      auto &n = nodes_.back();
      node_at.insert(std::make_pair(p, &n));
      for (auto &&m : nodes_) {
        if (is_passible(m.position, n.position) && m.position != n.position) {
          node::connect(distance(m.position, n.position), &m, &n);
        }
      }
    }

    auto remove_edges_to(const node *to) -> void {
      for (auto &&node : nodes_) {
        node.edges.remove_if([to](const edge &edge) { return edge.end == to; });
      }
    }

    auto remove_newest_node() -> void {
      remove_edges_to(&nodes_.back());
      nodes_.pop_back();
    }

  public:
    template <std::size_t Width, std::size_t Height>
    solver(const cart &cart, const map<Width, Height> &map)
        : cart_{cart}, walls_{}, nodes_{}, node_at{} {
      for (auto &&rect : map.get_blocks()) {
        auto l = rect.left - cart.width + Width / 10000.;
        auto r = rect.right - Width / 10000.;
        auto t = rect.top - cart.height + Height / 10000.;
        auto b = rect.bottom - Height / 10000.;

        walls_.push_front(line{point{l, t}, point{r, t}});
        walls_.push_front(line{point{l, b}, point{r, b}});
        walls_.push_front(line{point{l, t}, point{l, b}});
        walls_.push_front(line{point{r, t}, point{r, b}});
      }

      auto l = -(Width / 10000.);
      auto r = Width - cart.width + Width / 10000.;
      auto t = -(Height / 10000.);
      auto b = Height - cart.width + Height / 10000.;

      walls_.push_front(line{point{l, t}, point{r, t}});
      walls_.push_front(line{point{l, b}, point{r, b}});
      walls_.push_front(line{point{l, t}, point{l, b}});
      walls_.push_front(line{point{r, t}, point{r, b}});

      for (auto &&rect : map.get_blocks()) {
        auto l = rect.left - cart.width;
        auto r = rect.right;
        auto t = rect.top - cart.height;
        auto b = rect.bottom;

        add_node_at(point{l, t});
        add_node_at(point{l, b});
        add_node_at(point{r, t});
        add_node_at(point{r, b});
      }
    }

    auto calculate_costs(const point &start, const point &goal) -> void {
      auto *start_node = node_at[start];
      auto *goal_node = node_at[goal];
      for (auto &node : nodes_) {
        node.total_cost = std::numeric_limits<unsigned long long>::max() / 2;
        node.sure = false;
      }
      std::priority_queue<node *, std::vector<node *>, node_comparator>
          presumed{};
      goal_node->from = nullptr;
      start_node->total_cost = 0;
      start_node->from = nullptr;
      presumed.push(start_node);

      [&presumed, goal_node] {
        while (!presumed.empty()) {
          auto *nearest = presumed.top();
          presumed.pop();
          if (nearest->sure) {
            continue;
          }
          nearest->sure = true;
          for (auto &&edge : nearest->edges) {
            auto new_total_cost = nearest->total_cost + edge.cost;
            if (edge.end->total_cost > new_total_cost) {
              edge.end->total_cost = new_total_cost;
              edge.end->from = nearest;
              if (edge.end == goal_node) {
                return;
              }
              presumed.push(edge.end);
            }
          }
        }
      }();
    }

    auto find_path(const point &start, const point &goal) -> path {
      bool start_existed = node_at.count(start) == 1;
      bool goal_existed = node_at.count(goal) == 1;

      add_node_at(start);
      add_node_at(goal);

      calculate_costs(start, goal);

      auto *goal_node = node_at[goal];
      if (goal_node->from == nullptr) {
        return path::invalid();
      }

      std::forward_list<point> waypoints{};
      for (auto *n = goal_node; n != nullptr; n = n->from) {
        waypoints.push_front(n->position);
      }

      if (!start_existed) {
        remove_newest_node();
      }
      if (!goal_existed) {
        remove_newest_node();
      }

      return path{std::move(waypoints)};
    }

    auto get_nodes() const -> const std::deque<node> & { return nodes_; }

    auto get_walls() const -> const std::forward_list<line> & { return walls_; }

    auto get_cart() const -> const ziggygo::cart & { return cart_; }

    solver(const solver &) = default;
  };

  template <std::size_t Width, std::size_t Height>
  auto make_solver(const cart &cart, const map<Width, Height> &map) -> solver {
    return solver{cart, map};
  }
} // namespace ziggygo

#endif
