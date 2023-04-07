cmake_minimum_required(VERSION 3.10)
project(app)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)
pkg_check_modules(adwaita REQUIRED libadwaita-1)

include_directories(${GTK4_INCLUDE_DIRS} ${adwaita_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS} ${adwaita_LIBRARY_DIRS})
add_definitions(${GTK4_CFLAGS_OTHER} ${adwaita_CFLAGS_OTHER})

add_executable(app main.cpp)
target_link_libraries(app ${GTK4_LIBRARIES} ${adwaita_LIBRARIES})