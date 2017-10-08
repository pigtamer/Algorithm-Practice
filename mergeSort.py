from collections import deque
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt

def merge(lhs, rhs):
    merged,lhs,rhs = deque(),deque(lhs),deque(rhs)
    while lhs and rhs: # lhs and rhs not empty
        merged.append(lhs.popleft() if lhs[0] <= rhs[0] else rhs.popleft())
    merged.extend(rhs if rhs else lhs)
    return list(merged)

def mergeSortter(InputList):
    if len(InputList) <= 1:
        return InputList #already sorted.
    middle = int(len(InputList) // 2)
    lhs = mergeSortter(InputList[:middle]) # all elements on lhs side, recursive
    rhs = mergeSortter(InputList[middle:]) #all elements on rhs side, recursive
    return merge(lhs, rhs)

sns.set()
a = mergeSortter(np.floor(100*np.random.rand(100)))
print(a)
plt.figure(figsize=(8,6))
plt.plot(a)
plt.show()
