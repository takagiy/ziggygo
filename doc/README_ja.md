<!--
  Copyright (c) TakagiY 2019
  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)
-->

[English](/doc/README.md) | Japanese

# Solver
ライブラリの使用者が必要としているものはおそらく`solver`です。

`solver`のコンストラクタは障害物の配置とカートがどれだけ太っているかを知るために`map`と`cart`を取ります。

```c++
auto map = ...;

auto solver = ziggygo::solver{map, ziggygo::cart{100, 100}};
```

そうすると、`solver`はマップ上の二点の間の、カートが通過することができる最短経路を見つけることができます。

```c++
solver.find_path(ziggygo::point{100, 350}, ziggygo::point{500, 700});
```

# Creating a map
マップはいくつかの`block`から構成されます。テンプレートパラメータ(`<1000, 1000>`のような)はマップの幅と高さを表しています。

```c++
auto map = ziggygo::map<1000, 1000>{
    ziggygo::block{100, 100}.at(100, 200),
    ziggygo::block{800, 50}.at(0, 600),
    ziggygo::block{50, 350}.at(700, 200),
    ziggygo::block{100, 200}.at(300, 300)
};
```

下のコードは幅が50で高さが350, オフセットが(x: 700, y:200)のブロックを表します。

```c++
block{50, 350}.at(700, 200)
```

# Path
`path`は`solver::find_path`によって返されます。`path`は経路上のスタートとゴールを含む全ての経由地点のリストを持ちます。あなたはいくつかの方法で`path`と仕事ができます。

1. `operator->`によって`path`を`std::forward_list<point>`として扱えます。

```c++
// call std::forward_list::pop_front
path->pop_front();
```

2. `path`は*range-based for loop*のためのインターフェース, `path::begin`と`path::end`を提供します。

```c++
for(auto&& waypoint : path) {
    ...
}
```

`solver::find_path`は経路が見つからなかったときに無効な`path`を返します。これは`path::avails`によって確認できます。

```c++
if(!path.avails()) {
    // Path is invalid. There is nothing we can do.
    return;
}
```

# Point
`point`は以下の簡単な構造体です。

```c++
struct point {
    double x;
    double y;
};
```
