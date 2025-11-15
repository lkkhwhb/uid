#include <pybind11/pybind11.h>
#include "uid.h" 

namespace py = pybind11;
PYBIND11_MODULE(_core, m) {
    m.doc() = "Core C++ implementation for the uid package";

    m.def(
        "_id",
        &UltraFastId::generate_id,
        "Generates a high-performance random unique ID.",
        py::arg("k") = 12
    );
}