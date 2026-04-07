# FIFO Queue - C++

Two independent implementations of a FIFO (*First In, First Out*) queue in C++:

- **`FIFO`** - linked list based implementation
- **`array_FIFO`** - circular buffer (array) based implementation

Both versions share the same public methods and use the same `QInfo` data structure.

---

## Project Structure

```
FIFO_queue/
├── FIFO.sln                    # Visual Studio solution
├── FIFO/                       # Linked list implementation
│   ├── main.cpp
│   ├── Fifo.h / Fifo.cpp       # FQueue + FQItem + FifoException
│   └── Global.h / Global.cpp   # QInfo struct
└── array_FIFO/                 # Circular buffer implementation
    ├── main.cpp
    ├── Fifo.h / Fifo.cpp       # FQueue + FifoException
    └── Global.h / Global.cpp   # QInfo struct
```

---

## Data Structure `QInfo`

Each element stored in the queue is of type `QInfo` (aliased as `QINFO`):

```cpp
struct QInfo {
    int  key;    // element value
    int* pTab;   // dynamic array of two integers
};
```

Constructor: `QInfo(int key, int a, int b)` - creates an element with key `key` and array `{a, b}`.

---

## `FQueue` Methods

Both implementations share the same methods:

| Method | Description |
|---|---|
| `FQEmpty()` | Returns `true` if the queue is empty |
| `FQFull()` | *(array_FIFO only)* Returns `true` if the queue is full |
| `FQEnqueue(QINFO* p)` | Adds an element to the back of the queue |
| `FQDequeue()` | Removes and returns the element at the front |
| `FQDel()` | Removes the front element without returning it |
| `FQClear()` | Removes all elements |
| `FQPrint()` | Prints the entire queue contents |

---

## Error Handling

Both versions throw a `FifoException` on invalid operations:

| Error code | Value | Description |
|---|---|---|
| `FIFO_OVERFLOW` | `0x01` | Memory allocation failure / queue full |
| `FIFO_UNDERFLOW` | `0x02` | Dequeue attempted on an empty queue |
| `FIFO_SIZE` | `0x03` | *(array_FIFO only)* Capacity less than 2 |

```cpp
try {
    q.FQDequeue();
}
catch (FifoException& e) {
    cerr << e.getReason() << endl;
}
```

---

## Implementations

### FIFO - Linked List

The queue is built from dynamically allocated `FQItem` nodes. Each node holds a pointer to a `QINFO` object and a pointer to the next node. The queue grows dynamically with no upper size limit.

```cpp
FQueue q;
QINFO* item = new QINFO(1, 10, 20);
q.FQEnqueue(item);
QINFO* out = q.FQDequeue();
```

### array_FIFO - Circular Buffer

The queue is backed by a pre-allocated array of pointers with a fixed capacity. Head (`nHead`) and tail (`nTail`) indices advance cyclically using modulo arithmetic, allowing the queue to be filled and drained repeatedly without shifting elements. Capacity is set at construction time and must be at least 2.

```cpp
FQueue q(8); // queue with capacity of 8 elements
QINFO* item = new QINFO(1, 10, 20);
q.FQEnqueue(item);
QINFO* out = q.FQDequeue();
```

---

## Build

The project is configured for **Visual Studio 2022** (MSVC v143 toolset, x64).

1. Open `FIFO.sln` in Visual Studio.
2. Set `FIFO` or `array_FIFO` as the startup project.
3. Build and run (Debug / Release, x64).

Compiled binaries are placed in `x64/Debug/`.

---

## Comparison

| Feature | Linked List (`FIFO`) | Circular Buffer (`array_FIFO`) |
|---|---|---|
| Capacity | Unlimited (dynamic) | Constant, set at construction |
| Memory allocation | Per element | Single allocation in advance |
| Memory overhead | Higher (node pointers) | Lower and predictable |
| Overflow detection | Allocation failure only | Explicit `FQFull()` check |
