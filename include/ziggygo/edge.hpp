// Copyright (c) TakagiY 2019
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_EDGE
#define COM_GITHUB_TAKAGIY_ZIGGYGO_EDGE

#include "./declare.hpp"

namespace ziggygo {
  struct edge {
    unsigned long long cost;
    node *end;
  };
} // namespace ziggygo

#endif
