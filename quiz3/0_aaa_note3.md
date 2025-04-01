# Mistake
- ระวัง index โดยเฉพาะสลับ (x,y) หรือการใช้ (i,j) คู่ loop for i
- ระวังเช็ค `ny>N, ny<M`
- จะหา cycle ใน undirected ระวังวนไปเจอ pa
  ```
  if (vis[v] && v != pa)
      notcycle = 0;
  if (vis[v])
      continue;
  q.push({v, u});
  ```
- vector<vector<int>> ดีกว่า
- แยก array ดีกว่าทำ vector<pair>
- อย่าลืม set pa[i]
- in the middle : ใช้ stack(DFS) ไม่ผ่าน แต่ใช้ queue(BFS) ผ่าน => ใช้ queue มันก้าวสั้นกว่า
- unsigned long long กับ 2^30
- ถ้ารันรับค่าไม่ได้ ให้เช็คว่า vector ได้ resize ยัง
- ระวัง `dist[v] <= w + ww`
- floynd-warshell อย่าลืม set a[i][i] = 0 ตอนแรก
- floynd-warshell เรียง k, i, j เท่านั้น!!
- floynd-warshell เช็ค neg ว่าพอทำไปแล้ว a[i][i] < 0


# Tips
- tuple
  ```
  tuple<int, int, int> qq = q.front();
  u = get<0>(qq);
  ```
- Exchange : ทำ floynd-warshell O(N^3), ทำ break หาก profit โผล่มาก็ได้
    ```
    A[i][j] = max(A[i][j], A[i][k] * A[k][j]);
    if (i == j) profit |= (A[i][j] > 1);
  ```


# Wired
- Detecting Cycle (ex05m1_cycle)
  - 512 MB is every small. it has to use map path and vector vis
    ```
    map<int, list<int>> path;
    vector<bool> vis;
    ```
  - to check if there a cycle -> queue <u , pa>
- Cycle in Tree : ถ้า function ไม่ใช่ void แล้วไม่มีอะไร return กลับมา อาจขึ้น - ได้
- Connection : หาว่าในระยะ degree = 0 ถึง k มี node กี่ตัวมากสุด (N=1000) เลยวนเช็ค DFS ทุกๆตัวได้เลย
- Perimeter : อ๋อง อ่านโจทย์ไม่เข้าใจ
- Task Planning : ทำ topology
- Graph Coloring ไม่ค่อยเกต แต่คือ
  - ถ้า f==N ถือว่าจบ หา tmp = color สูงสุด แล้ว ans = min(ans,tmp)
  - ถ้ายัง วนลูปหาสี assign ให้น้อยสุด จาก 1->N
    - ถ้า i > ans // อย่าใช้สีเกิน ans ที่เคยตอบได้ และ เคยใช้สีน้อยกว่านี้ -> break
    - color[u] = i
    - check(u) // วนทุกๆ v ที่ติด u ว่าสีตรงไหม
    - ถ้าไม่ตรงทั้งหมด solve(u+1) หา node index ถัดไป
    - แต่ยังอยู่ในลูป คอยวนมาเช็คกรณีแบบ 2->3 ดีกว่าใน ans = 4
- Clique : ทำการตัดจบ state search 0/1 โดยว่าถ้า now + quicksum ที่เหลือด้านหลังมันรวมได้ไม่มากกว่า ans -> อันนี้ไม่ใช่คำตอบแน่ๆ

# Rerun
- Cycle in Tree 
- Largest Diff Path (95/100)
- catapult

# list of chore
: it's a list
: wrongggg. it's a list, a list of chore



  
ex05h1_rank
a58_q3_p3_Pand
66_q3a_sandworm
------------
ทวนก่อนนอน
------------
ex06m1_massrelay (ปล่อยมันไปเถอะ)
a61_q2_farthest (90/100)