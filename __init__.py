# Import the function from our compiled C++ module (_core)
try:
    from ._core import _id
except ImportError:
    # This provides a helpful error if the C++ extension failed to compile
    def _id(k=12):
        raise ImportError("uid C++ extension not built. Please check your compiler setup and reinstall.")

# This defines the public API of the package
__all__ = ["_id"]