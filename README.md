# Gray scale Image Converter

Convert an image to its grayscale equivalent

# Features

OpenCV with C++
OpenMP for multithreading
Smart Pointers used .


# Running the Code

To generate the executable file 
```sh
$ g++ -ggdb `pkg-config --cflags --libs opencv` gray2.cpp -o gray2 -fopenmp -std=c++14
```

To run the executable,
```sh
$ ./gray2 <filenames>
```

