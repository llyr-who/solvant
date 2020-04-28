# solvant [![Codacy Badge](https://api.codacy.com/project/badge/Grade/d33593faf7ee4367a5fc0909531dfb31)](https://app.codacy.com/manual/llyr-who/solvant?utm_source=github.com&utm_medium=referral&utm_content=llyr-who/solvant&utm_campaign=Badge_Grade_Dashboard)

## Building

To build

`make`

To test

`make test`

To clean

`make clean`

To produce different builds (e.g. Release), run

`make BUILD_TYPE=<build-type>`

If no `BUILD_TYPE` is entered, it defaults to Debug.

To generate documentation, make sure doxygen is installed. More specifically the packages, `doxygen`, `doxygen-gui` and
`graph-viz`.

Once these packages are installed you can run

`cd build && make docs && google-chrome docs/html/index.html`

For basic usage see `examples`.

