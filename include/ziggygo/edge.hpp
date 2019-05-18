#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_EDGE
#define COM_GITHUB_TAKAGIY_ZIGGYGO_EDGE

#include "./declare.hpp"

namespace ziggygo {
    struct edge {
        unsigned long long cost;
        const node* end;
    };
}

#endif
