# Deck
Example of Deck with template class and use of c++ std lib

# Build
mkdir build
cd build
cmake ..
make

For mac you can use instead
cmake .. -G Xcode
xcodebuild

# Run
with command ./Deck


## Test framework
git subtree add --prefix=third/catch2 https://github.com/catchorg/Catch2.git v3.7.0 --squash
