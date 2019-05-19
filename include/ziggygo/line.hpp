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

      auto cnls = cross_norm(this_, l.start - this->start);
      auto cnle = cross_norm(this_, l.end - this->start);
      auto cnts = cross_norm(l_, this->start - l.start);
      auto cnte = cross_norm(l_, this->end - l.start);

      return (cnls * cnle < 0 && cnts * cnte < 0) || (cnls == 0 || cnle == 0 || cnts == 0 || cnte == 0);
    }
  };
}; // namespace ziggygo

#endif
