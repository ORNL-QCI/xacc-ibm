#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(pyxaccibm, m) {
    m.doc() = "Python bindings for XACC. XACC provides a plugin infrastructure for "
    		"programming, compiling, and executing quantum kernels in a language and "
    		"hardware agnostic manner.";
}
