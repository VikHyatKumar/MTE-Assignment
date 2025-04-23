A priority queue is a data structure that stores elements such that each element is associated with a priority. Elements with higher priority are dequeued before elements with lower priority. If two elements have the same priority, their order of removal depends on the implementation (e.g., FIFO for equal priorities).

### Key Operations:
1. **Insert (Push)**: Add an element to the queue with a given priority.
2. **Extract (Pop)**: Remove and return the element with the highest priority.
3. **Peek (Top)**: Retrieve the element with the highest priority without removing it.

### Applications in Algorithm Design:
1. **Dijkstra's Algorithm**: Used to find the shortest path in a graph.
2. **A* Search Algorithm**: Utilized in pathfinding and graph traversal.
3. **Huffman Encoding**: Constructs optimal prefix codes for data compression.
4. **Task Scheduling**: Manages tasks based on priority in operating systems.
5. **Event Simulation**: Handles events in order of their scheduled time.

Priority queues are often implemented using **heaps** (e.g., binary heap, Fibonacci heap) for efficient operations.