# Overview
[u-blox GPS receivers](https://www.u-blox.com/en/position-time)
use a UBX binary protocol to transmit GPS data to a host computer using
asynchronous serial ports. This project provides a **headers only** library
implemented in C++(11), which implements all the messages as well as wrapping 
transport protocol used in **u-blox 4/5/6/7** devices.

# UBLOX Library
The library uses [COMMS library](https://github.com/arobenko/comms_champion#comms-library)
from [comms_champion](https://github.com/arobenko/comms_champion) project 
to specify all the messages resulting in clear, concise,
and very efficient code.

The ublox binary protocol is huge and it is unlikely that any embedded product
will require support for all the messages the protocol defines. This library
allows cherry-picking limited number of the selected messages the product requires,
which provides a great flexibility in terms of the final code size.

Full [doxygen](www.doxygen.org) generated documentation with the full tutorial inside can be
downloaded as [zip archive](https://dl.dropboxusercontent.com/u/46999418/ublox/doc_ublox.zip)
or browsed online [here](https://dl.dropboxusercontent.com/u/46999418/ublox/html/index.html).

# CommsChampion Plugin
In addition to the library described above, this project provides a protocol
plugin for the [CommsChampion Tool](https://github.com/arobenko/comms_champion#commschampion-tool)
from the same [comms_champion](https://github.com/arobenko/comms_champion) project,
which will allow visual analysis of the u-blox binary protocol traffic.

# Licence
The source code of [UBLOX Library](#ublox-library) as well as [CommsChampion Plugin](#commschampion-plugin) 
from this repository is licensed under GPLv3. 
It can be used in any product as long as its sources remain open and
have the same or other compatible license. As the author and full copyright
owner of this product I can provide a commercial license as well, please refer
to [Contact Information](#contact-information) below and get in touch with
me if you need one.

# How to Build
This project uses [CMake](https://cmake.org) cross-platform build system to
generate required build files native to the platform.

- Build and install all the necessary components from the 
[comms_champion](https://github.com/arobenko/comms_champion) project following
[instructions](https://github.com/arobenko/comms_champion#how-to-build).

- Create a separate build directory for this project somewhere and navigate there.

>$> mkdir /some/build/dir && cd /some/build/dir

- Generate Makefiles (or any other build environment) choosing the same build type
as when building the [comms_champion](https://github.com/arobenko/comms_champion)
sources, and providing path to the install directory of the latter using **UBLOX_CC_INSTALL_PATH**
variable.

>$> cmake -DCMAKE_BUILD_TYPE=Release -DCC_INSTALL_PATH= /path/to/comms_champion/build/install /path/to/ublox/sources

- Build and install.

>$> make install

After the build is complete, all the binaries, headers, libraries will reside
in **install** subdirectory of the directory chosen for build (/some/build/dir) .

In addition to built-in options/variables of CMake, such as **CMAKE_BUILD_TYPE** or
**CMAKE_TOOLCHAIN_FILE**, the following ones can be used:

- **UBLOX_LIB_ONLY**=ON/OFF - Exclude compilation of all the sources, install only
**UBLOX** Library. Default value is **OFF**, i.e. the plugin to CommsChampion gets built.

- **UBLOX_CC_PLUGIN**=ON/OFF - Include/Exclude plugin for CommsChampion tool.
Default value is **ON**

- **UBLOX_CC_PLUGIN_COPY_TO_CC_INSTALL_PATH**=ON/OFF - Install plugin for 
CommsChampion into **UBLOX_CC_INSTALL_PATH** as well as local installation path. 
Default value is **ON**.

- **UBLOX_QT_DIR**=/path/to/qt - Path to custom build of **QT5** if it cannot be
found in standard system directories.

For example, discard all other tools, just install the **UBLOX** library:

>$> cd /path/to/ublox/sources

>$> mkdir build && cd build

>$> cmake -DCMAKE_BUILD_TYPE=Release UBLOX_CC_INSTALL_PATH=/path/to/comms_champioin/sources -DUBLOX_LIB_ONLY=ON ..

>$> make install 

The example above will skip build of any tool available, it will just install 
the **UBLOX** library headers in **install/include** subdirectory

## Building Documentation
The documentation is not created during normal build process. The documentation of
the [UBLOX Library](#ublox-library) can be generated by building **doc_ublox**
target:
 
>$> make doc_ublox

The HTML documentation will reside in **install/doc/ublox/html** subdirectory.

**NOTE**, that you must have 
[Doxygen](www.doxygen.org) 
and [Dia](https://wiki.gnome.org/Apps/Dia) 
being installed on your system in order to be able to properly generate the 
documentation.

# Contact Information
For bug reports, feature requests, or any other question you may open an issue
here in **github** or e-mail me directly to: **arobenko@gmail.com**

