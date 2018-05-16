[![Build Status](http://ci.eclipse.org/xacc/buildStatus/icon?job=xacc-ibm-ci)](http://ci.eclipse.org/xacc/job/xacc-ibm-ci/)

# XACC Plugins for working with the IBM Quantum Experience
This plugin for XACC provide an Accelerator implementation targeting the remote IBM Quantum Experience infrastructure.

Installation
------------
With the XACC framework installed, users can choose a couple ways to install these plugins - using Python/Pip
```bash
$ python -m pip install --user .
```
or CMake and Make without Python support
```bash
$ mkdir build && cd build
$ cmake ..
$ make install 
```
or with Python support
```bash
$ cmake .. -DXACC_DIR=$(python -m pyxacc -L)
$ make install
```

Documentation
-------------

* [XACC Website and Documentation ](https://xacc.readthedocs.io)

Questions, Bug Reporting, and Issue Tracking
--------------------------------------------

Questions, bug reporting and issue tracking are provided by GitHub. Please
report all bugs by creating a new issue with the bug tag. You can ask
questions by creating a new issue with the question tag.

License
-------

XACC-IBM is licensed - [BSD 3-Clause](LICENSE).
