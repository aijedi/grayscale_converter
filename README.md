# Gray scale Image Converter

Convert an image to its grayscale equivalent

# Prequisites

OpenCV with C++ libraries must be installed .
Installation instructions can be found here : https://www.learnopencv.com/install-opencv3-on-ubuntu/

C++14 required for running smart pointers .
Installation instructions can be found here : http://scholtyssek.org/blog/2015/06/11/install-gcc-with-c14-support-on-ubuntumint/

# Features

- OpenCV with C++
- OpenMP for multithreading
- Smart Pointers used .


# Running the Code

To generate the executable file 
```sh
$ g++ -ggdb `pkg-config --cflags --libs opencv` gray2.cpp -o gray2 -fopenmp -std=c++14
```

To run the executable,
```sh
$ ./gray2 <filenames>
```

