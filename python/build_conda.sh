#! /bin/bash
cp -r ../src .
swig -c++ -python -py3 abarth.i
#swig -c++  -includeall  -python abarth.i
python setup.py build_ext --inplace
python tests/test.py