# UID

A tiny Python package for generating unique IDs at extremely high speed. The default length is 11 characters, but you can choose any length you want — the only real limit is your hardware.

The core is written in C++, using a 64-character alphabet and a fast, secure random generator. On an Intel i5 12th-gen U-series processor, it reaches roughly three to four million IDs per second. Faster CPUs can go even higher.

## Usage

```python
import uid

print(uid._id(k=32))   # custom length
print(uid._id())       # defaults to 11
```

Both calls return a unique, randomly generated ID as a string.

---

## Comparison

> Tested on Intel i5 12th Gen U series CPU

| Feature                  | UID (this package) | Python `uuid.uuid4` |
| ------------------------ | ------------------ | ------------------- |
| Speed                    | ~4,000,000 ID/s    | ~500,000 ID/s       |
| Language                 | C++ core           | Pure Python         |
| Charset                  | 64-character set   | Hexadecimal         |
| Default length           | 11 chars           | 32 hex chars        |
| Custom length            | Yes                | No                  |
| Cryptographically secure | Yes                | Yes                 |
