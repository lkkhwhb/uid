try:
    from ._core import _id
except ImportError:
    def _id(k=12):
        raise ImportError("uid C++ extension not built. Please check your compiler setup and reinstall.")

__all__ = ["_id"]
