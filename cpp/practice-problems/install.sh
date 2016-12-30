if [ -d "include" ]; then
  echo "Dependencies already installed."
  exit 0
fi

# Download Google Test
mkdir include
cd include
git clone https://github.com/google/googletest.git
cd googletest
git checkout tags/release-1.8.0 > /dev/null 2>&1

# Build Google Test
mkdir build
cd build
cmake ..
make

echo "Installed dependencies."
