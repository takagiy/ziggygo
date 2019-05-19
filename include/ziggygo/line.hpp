// Copyright (c) TakagiY 2019
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_LINE
#define COM_GITHUB_TAKAGIY_ZIGGYGO_LINE

#include "./declare.hpp"
#include "./point.hpp"

namespace ziggygo {
  struct line {
    point start;
    point end;

    auto crosses(const line &l) const -> bool {
      auto this_ = this->end - this->start;
      auto l_ = l.end - l.start;

      return cross_norm(this_, l.start - this->start) *
                     cross_norm(this_, l.end - this->start) <=
                 0 &&
             cross_norm(l_, this->start - l.start) *
                     cross_norm(l_, this->end - l.start) <=
                 0;
    }
  };
}; // namespace ziggygo

#endif
