# Lem-in
Ants! Ants everywhere!!!

Usage: ./lem-in < ant_farms_examples/test[number of test]

Project goal is to read the given ant-farm (kind of graph) and find the best possible ways to move all ants from start to end in the shortest amount of time and moves.

Short rules:

1. Each room can only contain one ant at a time

2. At each turn program displays the ants that moved

3. At each turn ant could be moved only once and through a tube (the room at the receiving end must be empty)

4. No traffic jams

5. Any non compliant or empty lines will automatically stop the ant farm’s reading and program displays error message

6. In no way can your program quit in an unexpected manner (segfault, bus error, double free, etc)
