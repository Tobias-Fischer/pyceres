#define NOMINMAX
#include <limits>

#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
namespace py = pybind11;

#include "core/bindings.cc"
#include "factors/bindings.cc"
#include "glog.cc"
#include "helpers.h"

void bind_core(py::module&);
void bind_factors(py::module&);

PYBIND11_MODULE(pyceres, m) {
  m.doc() = "PyCeres";

  py::add_ostream_redirect(m, "ostream_redirect");
  init_glog(m);
  bind_core(m);

  py::module_ f = m.def_submodule("factors");
  bind_factors(f);
}
