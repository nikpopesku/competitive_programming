def count_less_equal(x, n):
    count = 0
    for i in range(1, n + 1):
        # Count elements in the i-th row that are <= x
        count += min(x // i, n)
    return count

def find_middle_element(n):
    left, right = 1, n * n
    middle_position = (n * n - 1) // 2

    while left < right:
        mid = (left + right) // 2
        if count_less_equal(mid, n) <= middle_position:
            left = mid + 1
        else:
            right = mid

    return left

n = int(input())
print(find_middle_element(n))