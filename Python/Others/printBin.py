from collections import deque

n = 16
numbers_queue = deque()
numbers_queue.append("1")

for i in range(n):
    front = numbers_queue.popleft()
    print("   ", front)
    numbers_queue.append(front + "0")
    numbers_queue.append(front + "1")
