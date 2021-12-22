# rp2040_test

## SETUP
Install [Visual Studio Code](https://code.visualstudio.com/Download)
### Linux
Run the following command in bash to install the required libraries
>sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential libstdc++-arm-none-eabi-newlib

### Windows
Install [Chocolatey](https://chocolatey.org/install#individual), it is a package manager for windows
>choco install cmake
>choco install gcc-arm-embedded
>choco install python
>choco install mingw
>choco install git

In Vscode install the following extentions:
- C/C++ Extension Pack

Make sure to set Cmake:Generator to MinGW Makefiles in the settings UI menu
