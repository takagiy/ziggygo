// Copyright (c) TakagiY 2019
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef COM_GITHUB_TAKAGIY_ZIGGYGO_EXTRA_SVG
#define COM_GITHUB_TAKAGIY_ZIGGYGO_EXTRA_SVG

#include "../cart.hpp"
#include "../declare.hpp"
#include "../path.hpp"
#include "../point.hpp"
#include "../solver.hpp"
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

      auto draw_circle(const point &center, const char *color, double r)
          -> void {
        fout_ << "<circle cx=\"" << center.x << "\" cy=\"" << center.y
              << "\" r=\"" << r << "\""
              << " stroke-width=\"0\""
              << " stroke=\"" << color << "\""
              << " fill=\"" << color << "\"/>\n";
      }

      auto draw_rect(const point &corner, const char *color, double width,
                     double height) -> void {
        fout_ << "<rect x=\"" << corner.x << "\" y=\"" << corner.y
              << "\" width=\"" << width << "\" height=\"" << height << "\""
              << " stroke-width=\"0\""
              << " stroke=\"" << color << "\""
              << " fill=\"" << color << "\"/>\n";
      }

      auto draw_box(const point &corner, const char *color, double width,
                    double height, double stroke_width) -> void {
        draw_line(corner, point{corner.x + width, corner.y}, color,
                  stroke_width);
        draw_line(point{corner.x, corner.y + height},
                  point{corner.x + width, corner.y + height}, color,
                  stroke_width);
        draw_line(corner, point{corner.x, corner.y + height}, color,
                  stroke_width);
        draw_line(point{corner.x + width, corner.y},
                  point{corner.x + width, corner.y + height}, color,
                  stroke_width);
      }

      template <std::size_t Width, std::size_t Height>
      auto draw(const solver &solver) -> svg & {
        for (auto &&node : solver.get_nodes()) {
          if (node.edges.empty()) {
            continue;
          }
          draw_rect(node.position, "yellow", solver.get_cart().width,
                    solver.get_cart().height);
        }
        for (auto &node : solver.get_nodes()) {
          if (node.edges.empty()) {
            continue;
          }
          draw_circle(node.position, "green", 10);
        }
        for (auto &&node : solver.get_nodes()) {
          for (auto &&edge : node.edges) {
            draw_line(node.position, edge.end->position, "green", 1);
          }
        }
        return *this;
      }

      template <std::size_t Width, std::size_t Height>
      auto draw(const map<Width, Height> &map) -> svg & {
        for (auto &&block : map.get_blocks()) {
          draw_rect(point{block.left, block.top}, "black",
                    block.right - block.left, block.bottom - block.top);
        }
        return *this;
      }

      auto draw(const path &path) -> svg & {
        auto prev = path.begin();
        auto p = std::next(prev);
        draw_circle(*prev, "red", 10);
        for (auto end = path.end(); p != end; ++p) {
          draw_line(*prev, *p, "red", 5);
          prev = p;
          draw_circle(*prev, "red", 10);
        }
        return *this;
      }

      auto draw(const path &path, const cart &cart) -> svg & {
        for (auto &&position : path) {
          draw_rect(position, "pink", cart.width, cart.height);
        }
        draw(path);
        return *this;
      }
    };
  } // namespace extra
} // namespace ziggygo

#endif
