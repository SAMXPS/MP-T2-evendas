cd sources/
make test

mv *.gcov ../gcov/
mv *.gcno ../gcov/

cd ../bin/
./test

cd ../sources/
mv *.gcda ../gcov/

cd ../gcov/
gcovr