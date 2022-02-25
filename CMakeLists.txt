cmake_minimum_required(VERSION 3.0.0)
project(textrpg)

set(sources
  "src/TextRPG.cpp")

set(headers
  "src/Headers/beggardialogue.h"
  "src/Headers/centralloop.h"
  "src/Headers/dungeon.h"
  "src/Headers/enemies.h"
  "src/Headers/inventory.h"
  "src/Headers/items.h"
  "src/Headers/player.h"
  "src/Headers/shop.h")

add_executable(textrpg ${sources} ${headers})
target_compile_features(textrpg PRIVATE cxx_std_17)
