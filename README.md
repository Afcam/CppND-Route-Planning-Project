# Route Planning Project

This repo contains the starter code for the Route Planning project.

<img src="map.png" width="600" height="450" />

## Cloning

When cloning this project, be sure to use the `--recurse-submodules` flag. Using HTTPS:
```
git clone https://github.com/udacity/CppND-Route-Planning-Project.git --recurse-submodules
```
or with SSH:
```
git clone git@github.com:udacity/CppND-Route-Planning-Project.git --recurse-submodules
```

## Dependencies for Running Locally
* cmake >= 3.11.3
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 7.4.0
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same instructions as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* IO2D
  * Installation instructions for all operating systems can be found [here](https://github.com/cpp-io2d/P0267_RefImpl/blob/master/BUILDING.md)
  * This library must be built in a place where CMake `find_package` will be able to find it
 

## Compiling and Running

### Compiling
To compile the project, first, create a `build` directory and change to that directory:
```
mkdir build && cd build
```
From within the `build` directory, then run `cmake` and `make` as follows:
```
cmake ..
make
```
### Running
The executable will be placed in the `build` directory. From within `build`, you can run the project as follows:
```
./OSM_A_star_search
```
Or to specify a map file:
```
./OSM_A_star_search -f ../<your_osm_file.osm>
```

## Testing

The testing executable is also placed in the `build` directory. From within `build`, you can run the unit tests as follows:
```
./test
```

## Troubleshooting
* Some students have reported issues in cmake to find io2d packages, make sure you have downloaded [this](https://github.com/cpp-io2d/P0267_RefImpl/blob/master/BUILDING.md#xcode-and-libc).
* For MAC Users cmake issues: Comment these lines from CMakeLists.txt under P0267_RefImpl
    ```
    if( NOT DEFINED IO2D_WITHOUT_SAMPLES )
	     add_subdirectory(P0267_RefImpl/Samples)
    endif()
    ```
    And then run "ALL_Build" and "install" in XCode.
    
    If any packages are missing try to install packages using 
    ```
    brew install pkg-config
    ```
 * For Ubuntu Linux IO2D installation errors, follow the given steps:
   ```
	sudo apt update
	sudo apt install build-essential
	sudo apt install cmake
	sudo apt install libcairo2-dev
	sudo apt install libgraphicsmagick1-dev
	sudo apt install libpng-dev

	git clone --recurse-submodules https://github.com/cpp-io2d/P0267_RefImpl
	cd P0267_RefImpl
	mkdir Debug
	cd Debug
	cmake --config Debug "-DCMAKE_BUILD_TYPE=Debug" ..
	cmake --build .
	sudo make install
   ```
     
 * If you are working on windows and unable to install IO2D:
      * Enable WSL (Windows Subsystem for Linux) and use a distribution like [Ubuntu](https://ubuntu.com/wsl).(available from the windows store): 
      * Install the required dependencies (compiler, cmake etc.) in the WSL(as mentioned above for ubuntu)
      * Configure CLion to use the WSL [toolchain](https://www.jetbrains.com/help/clion/how-to-use-wsl-development-environment-in-product.html#wsl-tooclhain)
      * Use the WSL toolchain to build the project
      * If you are still facing errors, visit this [link](https://github.com/udacity/CppND-Route-Planning-Project/issues/9).
     

* If you are facing errors with --config try to remove -- from the command.


## Coding Resources

#### Resources on coding practices
- For [beginners](https://code.tutsplus.com/tutorials/top-15-best-practices-for-writing-super-readable-code--net-8118) to write code with high readability.
- More [advanced](https://hackernoon.com/few-simple-rules-for-good-coding-my-15-years-experience-96cb29d4acd9) advice from an experienced developer.

#### Resources for performance optimization
- Tips for C and C++ [performance improvement code optimization](https://www.thegeekstuff.com/2015/01/c-cpp-code-optimization/).
- Efficient C++ [performance programming techniques](http://www.whigg.ac.cn/resource/program/CPP/201010/P020101023562491092566.pdf).

#### Resources on software testing
The test framework used in this project is the Google C++ test. It is recommended to know about testing now because it is an essential element in software development.

- Introduction to the [concepts](https://chromium.googlesource.com/external/github.com/google/googletest/+/refs/tags/release-1.8.0/googletest/docs/Primer.md) of Google C++ tests.
- [Examples-based](https://developer.ibm.com/technologies/systems/articles/au-googletestingframework/) introductory article of using C++ tests.
- Explanation of the Google C++ test from work with a [video tutorial](https://www.youtube.com/watch?v=16FI1-d2P4E).

#### Resources on CMake and Make
In the beginning, it is usually unclear what those build systems or build system generators are and how they can benefit us.

- Overview of [CMake](https://cmake.org/overview/) and how it manages cross-platform build processes.
- Introduction to CMake by [examples]() applies to single file and multiple directory projects.

**Please note that CMake isn't a build system. It's a build system generator. This is why we need to invoke make after running CMake. Running CMake generates Makefiles with the appropriate platform dependencies, and running make uses them.**

However, we don't need to write Make files, as CMake does this for us. It is good to understand build systems.

- Introduction to [Make](https://www.gnu.org/software/make/) and how it uses the Makefile generated by CMake to build the system.
- How to [write Makefiles](https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html). This is just for your information. It is already automated through CMake.


#### Further improvement
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [Best Practices](https://github.com/cpp-best-practices/cppbestpractices)
- [Overview of STL](https://en.wikipedia.org/wiki/C%2B%2B_Standard_Library)
- [Step-by-step Knowledge](https://knowledge.udacity.com/questions/267563#267762) answer about debugging your code using only dbg and dbg within vscode.
- [Type Inference in C++ (auto and decltype)](https://www.geeksforgeeks.org/type-inference-in-c-auto-and-decltype/)
- [Does 'auto' type assignments of a pointer in c++11 require '*'?](https://stackoverflow.com/questions/12773257/does-auto-type-assignments-of-a-pointer-in-c11-require)
- [Lambda expressions](https://en.cppreference.com/w/cpp/language/lambda)
- [Lambda expressions in C++](https://learn.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170&viewFallbackFrom=vs-2019)
- [this Knowledge answer ](https://knowledge.udacity.com/questions/267842#267946)for the recommended C++ references
- [Zeal](https://zealdocs.org/)
- 