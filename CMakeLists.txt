cmake_minimum_required(VERSION 3.5)

# Nom du projet
project(imac_light_corridor)

# Version du C++ utilisé
set(CMAKE_CXX_STANDARD 11)

# Inclusion des fichiers d'en-tête
include_directories(include)

# Recherche de la librairie GLFW3
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})

# Recherche de la librairie OpenGL
find_package(OpenGL REQUIRED)
include_directories(${PROJECT_NAME} PRIVATE ${OpenGL_INCLUDE_DIRS})

# Ajout des fichiers sources
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Création de l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Liens avec les librairies nécessaires
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw)

# Définition du chemin de sortie de l'exécutable
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# Définition d'une règle de construction pour exécuter le programme
add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Exécution de ${PROJECT_NAME}"
)

# Ajout d'une règle de construction pour le programme
add_custom_target(build
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}
    DEPENDS ${PROJECT_NAME}
    COMMENT "Construction de ${PROJECT_NAME}"
)

# Ajout d'une commande pour compiler et exécuter le programme
add_custom_target(execute
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target ${PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_CURRENT_SOURCE_DIR} ./bin/${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    COMMENT "Compilation et exécution de ${PROJECT_NAME}"
)

# Définition de la commande "make execute" pour exécuter le programme
add_custom_target(make_execute
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target execute
    DEPENDS execute
    COMMENT "Compilation et exécution de ${PROJECT_NAME} avec make execute"
)
