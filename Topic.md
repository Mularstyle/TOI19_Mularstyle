#  TOI Topic Lists
This is a `Draft` version of TOI topic lists summary
## 1.Data Structure

- 1.1 Array
- 1.2 Vector
- 1.3 Linked List
- 1.4 Set / Unordered_Set
- 1.5 Map / Unordered_Map
- 1.6 Stack
- 1.7 Queue
- 1.8 Priority Queue
- 1.9 Pair
- 1.10 Deque
- 1.11 Struct

## 2.Algorithm

- 2.1 Brute Force
	- 2.1.1 Iterative Complete Search
	- 2.1.2 Recursive Complete Search
	- 
-	2.2 Greedy

- 2.3 Divide and Conquer (ไม่รู้ใช้ไม่เป็น ☹)

- 2.4 Binary Search
	- 2.4.1 Binary search หาเลขบน array (BS ธรรมดา)
	- 2.4.2 Binary search บนคำตอบ (ex. หา น้อยสุด/มากสุดที่เป็นไปได้ตามเงื่อนไข)
		- implement ด้วยตัวเองทั้งหมด
		- ใช้ฟังก์ชั่น lower/upper bound

- 2.5 Dynamic Programming
	- 2.5.1 พื้นฐาน
		-  2.5.1.1 Approaches  
			- Top-down (Memoization)
			- Bottom-up (Tabulation)
		- 2.5.1.2Multi-Dimension-DP  (มันก็คือ DP ที่มีหลาย state)
	-	2.5.2 ประยุกต์
		- Prefix Sum/Quick Sum
			- 1D ประยุกต์กับบางข้อ
			- 2D/On-Grid
		- LIS
			- O(N^2) อย่าใช้เถอะขอล้อง
			- O(NlogN) ใช้ Binary-Search
		- Knuth DP
		- Partition
			- 1D
			- 2D On-Grid
		- Bitmask DP
		- Sliding Window

## Graph

### พื้นฐาน

- Graph representation
	- Adjacency Matrix
	- Adjacency List
	- Edge List
	
- Graph Traversal
	- DFS
	- BFS

- Terminology : cycle,path,component,degree,Etc.

- Tree/Graph properties

### ประยุกต์

- Disjoint Set Union

- Cycle Detect

- Shortest Path

	- Dijkstra (SSSP/MSSP)
		- dijkstra 1 เงื่อนไข (สนแค่ระยะทาง)
		- dijkstra หลายเงื่อนไข

	- Floyd-Warshall (APSP)

- Minimum Spanning Tree

	- Kruskal

	- Prim

- Topological Sort

	- Kahn

- Strongly Connected Components

	-	Tarjan

	-	Kosaraju

- Graph Visualization  (ดวงตาเห็นธรรม)
