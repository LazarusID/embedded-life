file(GLOB mock_SRC
    "*.h"
    "*.cpp"
)

add_library(mock ${mock_SRC})