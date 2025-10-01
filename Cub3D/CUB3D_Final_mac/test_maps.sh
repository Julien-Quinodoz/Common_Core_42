#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

PASSED=0
FAILED=0

# Function to run test
run_test() {
    local test_name="$1"
    local map_file="$2"
    local should_pass="$3"
    
    echo -n "Testing $test_name... "
    
    if ./cub3D "$map_file" > /dev/null 2>&1; then
        if [ "$should_pass" = "true" ]; then
            echo -e "${GREEN}PASS${NC}"
            ((PASSED++))
        else
            echo -e "${RED}FAIL (should have failed)${NC}"
            ((FAILED++))
        fi
    else
        if [ "$should_pass" = "false" ]; then
            echo -e "${GREEN}PASS${NC}"
            ((PASSED++))
        else
            echo -e "${RED}FAIL (should have passed)${NC}"
            ((FAILED++))
        fi
    fi
}

# Create test directory
mkdir -p test_maps

echo "Creating test maps..."

# Valid map
cat > test_maps/valid.cub << 'EOF'
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
DO ./textures/door.png
F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
EOF

# Invalid extension
cat > test_maps/wrong_ext.txt << 'EOF'
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
DO ./textures/door.png
F 220,100,0
C 225,30,0

1111111
1000001
100N001
1111111
EOF

# Missing texture
cat > test_maps/missing_texture.cub << 'EOF'
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
DO ./textures/door.png
F 220,100,0
C 225,30,0

1111111
1000001
100N001
1111111
EOF

# Duplicate texture
cat > test_maps/duplicate_texture.cub << 'EOF'
NO ./textures/north.png
NO ./textures/north2.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
DO ./textures/door.png
F 220,100,0
C 225,30,0

1111111
1000001
100N001
1111111
EOF

# Invalid RGB values
cat > test_maps/invalid_rgb.cub << 'EOF'
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
DO ./textures/door.png
F 256,100,0
C 225,30,0

1111111
1000001
100N001
1111111
EOF

# Missing RGB component
cat > test_maps/missing_rgb.cub << 'EOF'
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
DO ./textures/door.png
F 220,100
C 225,30,0

1111111
1000001
100N001
1111111
EOF

# No player
cat > test_maps/no_player.cub << 'EOF'
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
DO ./textures/door.png
F 220,100,0
C 225,30,0

1111111
1000001
1000001
1111111
EOF

# Multiple players
cat > test_maps/multiple_players.cub << 'EOF'
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
DO ./textures/door.png
F 220,100,0
C 225,30,0

1111111
100N001
100S001
1111111
EOF

# Map not enclosed (top)
cat > test_maps/not_enclosed_top.cub << 'EOF'
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
DO ./textures/door.png
F 220,100,0
C 225,30,0

0111111
1000001
100N001
1111111
EOF

# Map not enclosed (bottom)
cat > test_maps/not_enclosed_bottom.cub << 'EOF'
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
DO ./textures/door.png
F 220,100,0
C 225,30,0

1111111
1000001
100N001
1111110
EOF

# Map not enclosed (left)
cat > test_maps/not_enclosed_left.cub << 'EOF'
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
DO ./textures/door.png
F 220,100,0
C 225,30,0

1111111
0000001
100N001
1111111
EOF

# Map not enclosed (right)
cat > test_maps/not_enclosed_right.cub << 'EOF'
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
DO ./textures/door.png
F 220,100,0
C 225,30,0

1111111
1000000
100N001
1111111
EOF

# Map with hole (space adjacent to walkable area)
cat > test_maps/hole_in_map.cub << 'EOF'
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
DO ./textures/door.png
F 220,100,0
C 225,30,0

1111111
100 001
100N001
1111111
EOF

# Invalid character in map
cat > test_maps/invalid_char.cub << 'EOF'
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
DO ./textures/door.png
F 220,100,0
C 225,30,0

1111111
100X001
100N001
1111111
EOF

# Empty map
cat > test_maps/empty_map.cub << 'EOF'
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
DO ./textures/door.png
F 220,100,0
C 225,30,0

EOF

# Too few config lines
cat > test_maps/too_few_config.cub << 'EOF'
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
F 220,100,0
C 225,30,0

1111111
1000001
100N001
1111111
EOF

# Too many config lines
cat > test_maps/too_many_config.cub << 'EOF'
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
DO ./textures/door.png
DO ./textures/door2.png
F 220,100,0
C 225,30,0

1111111
1000001
100N001
1111111
EOF

# Map too large (43x43)
cat > test_maps/too_large.cub << 'EOF'
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
DO ./textures/door.png
F 220,100,0
C 225,30,0

1111111111111111111111111111111111111111111
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
100000000000000000000N000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1000000000000000000000000000000000000000001
1111111111111111111111111111111111111111111
EOF

echo "Compiling..."
make > /dev/null 2>&1

if [ ! -f "./cub3D" ]; then
    echo -e "${RED}Compilation failed!${NC}"
    exit 1
fi

echo -e "${YELLOW}Running tests...${NC}"
echo

# Run tests
run_test "Valid map" "test_maps/valid.cub" "true"
run_test "Wrong extension" "test_maps/wrong_ext.txt" "false"
run_test "Missing texture" "test_maps/missing_texture.cub" "false"
run_test "Duplicate texture" "test_maps/duplicate_texture.cub" "false"
run_test "Invalid RGB (>255)" "test_maps/invalid_rgb.cub" "false"
run_test "Missing RGB component" "test_maps/missing_rgb.cub" "false"
run_test "No player" "test_maps/no_player.cub" "false"
run_test "Multiple players" "test_maps/multiple_players.cub" "false"
run_test "Not enclosed (top)" "test_maps/not_enclosed_top.cub" "false"
run_test "Not enclosed (bottom)" "test_maps/not_enclosed_bottom.cub" "false"
run_test "Not enclosed (left)" "test_maps/not_enclosed_left.cub" "false"
run_test "Not enclosed (right)" "test_maps/not_enclosed_right.cub" "false"
run_test "Hole in map" "test_maps/hole_in_map.cub" "false"
run_test "Invalid character" "test_maps/invalid_char.cub" "false"
run_test "Empty map" "test_maps/empty_map.cub" "false"
run_test "Too few config lines" "test_maps/too_few_config.cub" "false"
run_test "Too many config lines" "test_maps/too_many_config.cub" "false"
run_test "Map too large" "test_maps/too_large.cub" "false"

echo
echo -e "${GREEN}Passed: $PASSED${NC}"
echo -e "${RED}Failed: $FAILED${NC}"

if [ $FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed!${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed!${NC}"
    exit 1
fi 