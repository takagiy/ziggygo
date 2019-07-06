<!--
  Copyright (c) TakagiY 2019
  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)
-->

# ziggygo [![Build Status](https://travis-ci.com/takagiy/ziggygo.svg?branch=master)](https://travis-ci.com/takagiy/ziggygo) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/137064ebc2f744b1af09fbbff5f08472)](https://app.codacy.com/app/takagiy/ziggygo?utm_source=github.com&utm_medium=referral&utm_content=takagiy/ziggygo&utm_campaign=Badge_Grade_Settings)

Find the shortest path in the field containing rectangular obstacles.

## Example
```c++
#include <ziggygo.hpp>
#include <ziggygo/extra.hpp>

auto main() -> int {
  // make a 1000 x 1000 map containing four obstacles
  auto map = ziggygo::map<1000, 1000>{
    ziggygo::block{100, 100}.at(100, 200),
    ziggygo::block{800, 50}.at(0, 600),
    ziggygo::block{50, 350}.at(700, 200),
    ziggygo::block{100, 200}.at(300, 300)
  };

  // make a solver by specifying the size of the cart(agent)
  auto solver = ziggygo::solver{ziggygo::cart{100, 100}, map};

  // find the shortest route between two points on the map
  auto path =
      solver.find_path(ziggygo::point{100, 350}, ziggygo::point{500, 700});

  // save the result as a svg image
  ziggygo::extra::svg("path.svg", 1000, 1000).draw(map).draw(path, ziggygo::cart{100, 100});
}
```

<div>

<img src="/doc/image/path.svg" alt="path.svg" width="600px">

* Black … obstacles
* Red … the shortest route
* Pink … shadows of the cart on a point

</div>

## [See more about this library in /doc/README.md](/doc/README.md)

## Usage
First, place this repository as a subdirectory of your project, and add below to your `CMakeLists.txt`

```cmake
add_subdirectory(ziggygo)
```

, or [install this package into your system](#installation) and ...

```cmake
find_package(ziggygo 0.1.0 REQUIRED)
```

Now, you can call the library in your project.

```cmake
target_link_libraries(your-exe ziggygo::ziggygo)
```

## Installation
You can install the package into your system with `cmake`.

```bash
mkdir build
cd build
cmake .. # Install to /usr/local(UNIX), c:/ProgramFiles/ziggygo(Windows)
         # or the specific place(`cmake .. -DCMAKE_INSTALL_PREFIX=/where/to/install`).
make install
```

