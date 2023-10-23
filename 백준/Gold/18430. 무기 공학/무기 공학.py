import sys
#sys.stdin = open('test.txt', 'r')
input = sys.stdin.readline
N, M = map(int, input().split())
nums = [[0] * (M + 1)] + [[0] + list(map(int, input().split())) for _ in range(N)]
ans = 0
dir = [(0, -1, 1, 0), (-1, 0, 0, -1), (-1, 0, 0, 1), (0, 1, 1, 0)]
checked = [[0] * (M + 1) for _ in range(N + 1)]
def OOB(r, c):
    return r < 1 or r > N or c < 1 or c > M
def dfs(depth, t):
    global ans
    if depth == N * M:
        ans = max(ans, t)
        return
    dfs(depth + 1, t)
    r, c = depth // M + 1, depth % M + 1
    if checked[r][c]:
        dfs(depth + 1, t)
        return
    for i in range(4):
        nr1, nc1 = r + dir[i][0], c + dir[i][1]
        nr2, nc2 = r + dir[i][2], c + dir[i][3]
        if not OOB(nr1, nc1) and not OOB(nr2, nc2) and not checked[nr1][nc1] and not checked[nr2][nc2]:
            tmp = nums[r][c] * 2 + nums[nr1][nc1] + nums[nr2][nc2]
            checked[r][c] = 1
            checked[nr1][nc1] = 1
            checked[nr2][nc2] = 1
            dfs(depth + 1, t + tmp)
            checked[r][c] = 0
            checked[nr1][nc1] = 0
            checked[nr2][nc2] = 0
    return
dfs(0, 0)
print(ans)
