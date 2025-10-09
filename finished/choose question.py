"""
问题描述

两位资深的审题专家，小蓝和小桥，各自收到了 NN 道题目。小蓝收到的题目难度依次为 A1,A2,…ANA1​,A2​,…AN​，小桥收到的题目难度依次为 B1,B2,…,BNB1​,B2​,…,BN​。

为了准备即将举行的竞赛，他们需要从各自收到的题目中选出一道，用于竞赛。通过商量，两人决定通过一种特殊的方式来选择题目：两人轮流删除一道自己手中的题目，直到各自只剩下一道题目。小蓝先删除，然后小桥删除，依此交替进行，直到最后两人手中都只剩下一道题目。

小桥希望最终两人剩下的两道题目的难度差尽可能小，而小蓝则希望难度差尽可能大。假设两人都采取最优策略，请问最终两人剩下的两道题目的难度差的绝对值是多少？
输入格式

    第一行包含一个整数 NN (1≤N≤1000)(1≤N≤1000)，表示每人初始的题目数量；
    第二行包含 NN 个整数 A1,A2,…,ANA1​,A2​,…,AN​（1≤Ai≤1031≤Ai​≤103），表示小蓝收到的题目难度；
    第三行包含 NN 个整数 B1,B2,…,BNB1​,B2​,…,BN​（1≤Bi≤1031≤Bi​≤103），表示小桥收到的题目难度。
"""

def main():
    # Read input size
    n = int(input())
    
    # Read arrays a and b
    a = [0] + [int(x) for x in input().split()]
    b = [0] + [int(x) for x in input().split()]
    
    # Sort arrays (excluding index 0)
    a[1:n+1] = sorted(a[1:n+1])
    b[1:n+1] = sorted(b[1:n+1])
    
    ans = 0
    for i in range(1, n+1):
        maxx = float('inf')  # Minimum difference for current a[i]
        for j in range(1, n+1):
            maxx = min(maxx, abs(a[i] - b[j]))
        ans = max(ans, maxx)  # Track maximum of minimum differences
    
    print(ans)

if __name__ == "__main__":
    main()

"""
def find_min_diff(arr, target):
    # Binary search to find the closest element in sorted arr to target
    left, right = 0, len(arr) - 1
    min_diff = float('inf')
    
    while left <= right:
        mid = (left + right) // 2
        min_diff = min(min_diff, abs(target - arr[mid]))
        if arr[mid] < target:
            left = mid + 1
        elif arr[mid] > target:
            right = mid - 1
        else:
            break  # Exact match found, no need to continue
    
    return min_diff

# Read input
n = int(input())
a = [0] + list(map(int, input().split()))
b = [0] + list(map(int, input().split()))

# Sort arrays (excluding index 0)
a[1:n+1] = sorted(a[1:n+1])
b[1:n+1] = sorted(b[1:n+1])

# Find maximum of minimum differences
ans = 0
for i in range(1, n+1):
    min_diff = find_min_diff(b[1:n+1], a[i])
    ans = max(ans, min_diff)

print(ans)
"""