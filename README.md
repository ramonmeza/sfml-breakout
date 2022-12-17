## Modern C++ Project Template

#### *A template for modern C++ projects.*


## Features

### `Visual Studio Code` Configuration Files

Included are workspace recommendation and settings files to help configure your `VSCode` workspace to integrate seamlessly with `CMake` and `C++`.


### `Github Actions`

Using [Github Actions](https://github.com/features/actions), upon pushing to and pulling into `main`, the included action will configure, build, and test your application on the latest `Windows`, `Ubuntu`, and `MacOS` platforms.


### `CMake` Integration

The project is set up with [`CMake`](https://cmake.org/) integration for simplified building and testing of your application.


### `Google Test`

Tests are written using [`Google Test`](https://github.com/google/googletest.git) and tested through `CTest`.


### MIT License

```
A short and simple permissive license with conditions only requiring preservation of copyright and license notices. Licensed works, modifications, and larger works may be distributed under different terms and without source code.
```
#### *Copied from [Choose A License](https://choosealicense.com/licenses/mit)*


## Understanding the Structure

### `apps`

The `apps` folder contains the source files to your main application. It also provides a `CMake` target executable called `app` that links to the `utils` library, defined in this template. If you need to link anything to your executable, that linkage is defined within `CMakeLists.txt` in this folder.


### `include`

The `include` folder contains the header files for your project. This file does not specify any `CMake` targets.


### `src`

All source files should be place in this directory. As it stands, this directory has subdirectories within it that are used to create libraries to be used in our app.

### `tests`

All tests should be placed within this directory. Currently, there are subdirectories which contain the implementation files for your libraries.
