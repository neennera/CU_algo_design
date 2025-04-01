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

# Rerun
- Cycle in Tree 
- Largest Diff Path (95/100)
- catapult

# list of chore
: it's a list
: wrongggg. it's a list, a list of chore




a66_q3a_sandworm
a58_q3_p3_PandG
ex05h1_rank
a61_q2_farthest
ex06m1_massrelay
------------------
a58_q3_p3a_hacking
a65_q3a_expressway
a66_f1_ev_truck	
a66_q4a_clique
a66_q3b_hex_map_v2
------------
a57_f4_journey
ex07m2_15puzzle
da67_f_travelling_tourist
a64_q4_closest_subset
ex07e3_coloring
a64_q4_path_sum
a65_q4_collector