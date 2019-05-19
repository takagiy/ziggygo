// Copyright (c) TakagiY 2019
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_MAP
#define COM_GITHUB_TAKAGIY_ZIGGYGO_MAP

#include "./declare.hpp"
#include <cstddef>
#include <initializer_list>
#include <vector>

namespace ziggygo {
  template <std::size_t Width, std::size_t Height>
  class map {
    friend class solver<Width, Height>;

    std::vector<block> blocks_;

  public:
    map(const std::initializer_list<block> &blocks) : blocks_{blocks} {}

    map(const map &) = default;

    auto blocks() const -> const std::vector<block> & { return blocks_; }
  };
} // namespace ziggygo

#endif
