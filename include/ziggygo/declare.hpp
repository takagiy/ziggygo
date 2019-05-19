// Copyright (c) TakagiY 2019
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_DECLARE
#define COM_GITHUB_TAKAGIY_ZIGGYGO_DECLARE

#include <cstddef>

namespace ziggygo {
  struct point;

  struct line;

  struct cart;

  struct block;

  struct path;

  struct node;

  struct edge;

  template <std::size_t, std::size_t>
  class map;

  template <std::size_t, std::size_t>
  class solver;
}; // namespace ziggygo

#endif
