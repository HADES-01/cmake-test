cmake -DTEST=ON -G "MinGW Makefiles" -S . -B build
CALL build.bat
ctest --test-dir build/tests