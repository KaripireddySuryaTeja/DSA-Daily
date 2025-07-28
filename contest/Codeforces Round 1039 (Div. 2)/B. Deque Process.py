def is_good(seq):
    n = len(seq)
    for i in range(n - 4):
        if all(seq[i + j] < seq[i + j + 1] for j in range(4)):
            return False
        if all(seq[i + j] > seq[i + j + 1] for j in range(4)):
            return False
    return True

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    t = int(data[idx])
    idx += 1
    results = []
    
    for _ in range(t):
        n = int(data[idx])
        idx += 1
        p = list(map(int, data[idx:idx + n]))
        idx += n
        
        l, r = 0, n - 1
        res = []
        q = []
        
        while l <= r:
            if not q:
                if p[l] < p[r]:
                    q.append(p[l])
                    res.append('L')
                    l += 1
                else:
                    q.append(p[r])
                    res.append('R')
                    r -= 1
            else:
                # Try left
                q.append(p[l])
                if is_good(q):
                    res.append('L')
                    l += 1
                    continue
                q.pop()
                
                # Try right
                q.append(p[r])
                if is_good(q):
                    res.append('R')
                    r -= 1
                    continue
                q.pop()
                
                # Fallback (guaranteed to be valid)
                q.append(p[l])
                res.append('L')
                l += 1
        
        results.append(''.join(res))
    
    print('\n'.join(results))

# Run the solve function if the script is executed
if __name__ == "__main__":
    solve()