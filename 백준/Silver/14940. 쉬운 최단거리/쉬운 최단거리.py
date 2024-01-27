import sys
from collections import deque
def get():
  return sys.stdin.readline().rstrip()
n, m = map(int, get().split())
board = [list(map(int, get().split())) for _ in range (n)]
answer = [[-1 for _ in range(m)] for _ in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
que = deque()
# Initailize
for i in range(n):
  for j in range(m):
    if board[i][j] == 0: answer[i][j] = 0
    elif board[i][j] == 2: 
      que.append((i, j))
      answer[i][j] = 0
while(que):
  cur_x, cur_y = que.popleft()
  cur_dist = answer[cur_x][cur_y]
  for i in range(4):
    temp_x = cur_x + dx[i]
    temp_y = cur_y + dy[i]
    if temp_x < 0 or temp_x >= n or temp_y < 0 or temp_y >= m:
      continue
    
    # 0이면 X
    if board[temp_x][temp_y] == 0:
      continue
    # -1이 아니면 Visited
    if answer[temp_x][temp_y] != -1: 
      continue
    que.append((temp_x, temp_y))
    answer[temp_x][temp_y] = cur_dist + 1
for temp_list in answer:
  print(' '.join(str(x) for x in temp_list))
