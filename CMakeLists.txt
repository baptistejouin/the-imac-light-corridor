cmake_minimum_required(VERSION 3.5)

# Nom du projet
project(imac_light_corridor)

# Version du C++ utilisé
set(CMAKE_CXX_STANDARD 17)

# Inclusion des fichiers d'en-tête
include_directories(include)

# Recherche de la librairie OpenGL
find_package(OpenGL REQUIRED)
include_directories(${PROJECT_NAME} PRIVATE ${OpenGL_INCLUDE_DIRS})

# Ajout des fichiers sources
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Création de l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# ---Add GLFW---
if(APPLE AND CMAKE_SYSTEM_NAME MATCHES "Darwin")
    find_package(glfw3 REQUIRED)
else()
    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    add_subdirectory(third_party/glfw)
endif()


# Liens avec les librairies nécessaires
target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES} glfw)

# Définition du chemin de sortie de l'exécutable
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# Définition d'une règle de construction pour exécuter le programme
add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Exécution de ${PROJECT_NAME}"
)
