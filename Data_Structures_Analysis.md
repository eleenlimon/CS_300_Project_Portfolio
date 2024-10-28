# Data Structures Analysis (C++)

## Overview
This analysis examines the run-time complexity and memory usage of the data structures utilized in Project One: `std::map` and `std::vector`.

### Data Structure: `std::map`
- **Run-time Complexity**:
  - **Insertion**: O(log n), due to the balanced tree structure underlying `std::map`.
  - **Lookup**: O(log n), with logarithmic complexity for searching a key-value pair.
  - **Deletion**: O(log n), as deleting an element involves rebalancing the tree.
- **Memory Usage**:
  - `std::map` requires O(n) space, where `n` is the number of elements, to store each key-value pair and associated pointers for tree structure maintenance.

### Data Structure: `std::vector`
- **Run-time Complexity**:
  - **Insertion at the end**: O(1) on average, thanks to amortized constant time, though resizing incurs an O(n) cost.
  - **Insertion in the middle**: O(n), since shifting elements is required.
  - **Lookup**: O(1), providing constant time access by index.
- **Memory Usage**:
  - Memory usage grows with the number of elements. Due to resizing, `std::vector` can have additional overhead, as it may allocate extra space when expanding to prevent frequent reallocations.

