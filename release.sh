#!/bin/bash
# Compiling for Linux
mkdir build
cd build &&
cmake .. -DCMAKE_BUILD_TYPE=Release &&
make &&
cd ..
cp build/bin/main main

# Compiling for Windows
mkdir build_win
cd build_win &&
cmake .. -DCMAKE_BUILD_TYPE=Release --toolchain ../mingw-w64-x86_64.cmake &&
make &&
cd ..
cp build_win/bin/main.exe .

# Zipping the build
rm release.zip
printf "vsync=true\n" > settings.txt
zip release.zip main main.exe libgcc_s_seh-1.dll libstdc++-6.dll assets/* LICENSE README.md settings.txt
rm main main.exe

# Making a new GitHub commit
git add .
git commit
git push origin main

# Creating a GitHub release
gh release create $1 release.zip
