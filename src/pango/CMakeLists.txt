
#link_libraries(uwimg++)

#link_directories(/home/swetko/local/Pangolin/build/src)
#include_directories(/home/swetko/local/Pangolin/build/src/include /home/swetko/local/Pangolin/include)

find_package(Pangolin QUIET)

if(Pangolin_FOUND)
  message(---------------------------------------------)
  message("Pangolin found!!!!")
  message("Building WITH Visualization")
  message(---------------------------------------------)
  
  link_libraries(${Pangolin_LIBRARIES})
  include_directories(${Pangolin_INCLUDE_DIRS})
  
  add_executable(harris test2-harris.cpp pango-utils.h)
  add_executable(panorama test2-panorama.cpp pango-utils.h)
  add_executable(projections test2-proj.cpp pango-utils.h)
else()
  message(---------------------------------------------)
  message("Pangolin NOT found")
  message("Building WITHOUT Visualization")
  message(---------------------------------------------)
endif()
