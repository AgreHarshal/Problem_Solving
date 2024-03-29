import math

def can_reach_destination(m, n, x, p, q, u, v):
    distance = math.sqrt((u - p)*2 + (v - q)*2)
    
    if distance % x == 0:
        return int(distance / x)
    else:
        return -1

# Read input values
m, n, x = map(int, input().split())
p, q = map(int, input().split())
u, v = map(int, input().split())

# Check if Kady can reach the destination and get the minimum jumps
result = can_reach_destination(m, n, x, p, q, u, v)
print(result)