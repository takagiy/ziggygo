// Copyright (c) TakagiY 2019
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_PATH
#define COM_GITHUB_TAKAGIY_ZIGGYGO_PATH

#include "./declare.hpp"
#include <forward_list>
#include <utility>

namespace ziggygo {
  class path {
    bool avails_;

    std::forward_list<point> waypoints_;

    path() : avails_{false}, waypoints_{} {}

  public:
    static auto invalid() -> path { return path{}; }

    path(const std::forward_list<point> &waypoints)
        : avails_{true}, waypoints_{waypoints} {}

    path(std::forward_list<point> &&waypoints)
        : avails_{true}, waypoints_{std::move(waypoints)} {}

    auto begin() noexcept -> std::forward_list<point>::iterator {
        return waypoints_.begin();
    }

    auto begin() const noexcept -> std::forward_list<point>::const_iterator {
        return waypoints_.begin();
    }

    auto end() noexcept -> std::forward_list<point>::iterator {
        return waypoints_.end();
    }
    
    auto end() const noexcept -> std::forward_list<point>::const_iterator {
        return waypoints_.end();
    }

    auto cbegin() const noexcept -> std::forward_list<point>::const_iterator {
      return waypoints_.cbegin();
    }

    auto cend() const noexcept -> std::forward_list<point>::const_iterator {
      return waypoints_.cend();
    }

    auto avails() -> bool { return avails_; }
  };
} // namespace ziggygo

#endif
