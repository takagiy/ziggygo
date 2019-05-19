// Copyright (c) TakagiY 2019
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_EXTRA_SVG
#define COM_GITHUB_TAKAGIY_ZIGGYGO_EXTRA_SVG

#include "../declare.hpp"
#include "../point.hpp"
#include <cstddef>
#include <forward_list>
#include <fstream>
#include <iterator>
#include <ostream>

namespace ziggygo {
  namespace extra {
    class svg {
      std::ofstream fout_;

    public:
      svg(const char *filename, double width, double height) : fout_{filename} {
        fout_ << "<svg xmlns=\"http://www.w3.org/2000/svg\" "
                 "xmlns:xlink=\"http://www.w3.org/1999/xlink\" width= \""
              << width << "\" height=\"" << height << "\">\n";
      }

      ~svg() { fout_ << "</svg>" << std::endl; }

      auto draw_line(const point &start, const point &end, const char *color,
                     double width = 1) -> void {
        fout_ << "<line x1=\"" << start.x << "\" y1=\"" << start.y << "\" x2=\""
              << end.x << "\" y2=\"" << end.y << "\" stroke-width=\"" << width
              << "\" stroke=\"" << color << "\" />\n";
      }

      auto draw_circle(const point &center, const char *color, double r) -> void {
        fout_ << "<circle cx=\"" << center.x << "\" cy=\"" << center.y
              << "\" r=\"" << r << "\""
              << " stroke-width=\"0\""
              << " stroke=\"" << color << "\""
              << " fill=\"" << color << "\"/>\n";
      }

      template <std::size_t Width, std::size_t Height>
      auto draw(const solver<Width, Height> &solver) -> svg & {
        for (auto &&wall : solver.walls()) {
          draw_line(wall.start, wall.end, "grey", 10);
        }
        for (auto &&node : solver.nodes()) {
          draw_circle(node.position, "green", 10);
          for (auto &&edge : node.edges) {
            draw_line(node.position, edge.end->position, "green", 1);
          }
        }
        return *this;
      }

      template <std::size_t Width, std::size_t Height>
      auto draw(const map<Width, Height> &map) -> svg & {
        for (auto &&block : map.blocks()) {
          draw_line(point{block.left, block.top}, point{block.right, block.top},
                    "black", 5);
          draw_line(point{block.left, block.bottom},
                    point{block.right, block.bottom}, "black", 5);
          draw_line(point{block.left, block.top},
                    point{block.left, block.bottom}, "black", 5);
          draw_line(point{block.right, block.top},
                    point{block.right, block.bottom}, "black", 5);
        }
        return *this;
      }

      auto draw(const std::forward_list<point> &path) -> svg & {
        auto prev = path.front();
        for (auto p = std::next(path.begin()), end = path.end(); p != end;
             ++p) {
          draw_line(prev, *p, "blue", 5);
          prev = *p;
        }
        return *this;
      }
    };
  } // namespace extra
} // namespace ziggygo

#endif
