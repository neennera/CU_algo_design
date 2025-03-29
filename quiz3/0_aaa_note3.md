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


# Tips
- tuple
  ```
  tuple<int, int, int> qq = q.front();
  u = get<0>(qq);
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

# list of chore
: it's a list
: wrongggg. it's a list, a list of chore



ex06e1_cable
da67_f_border_extend
a65_q3a_in_the_middle
a60b_q3_ikea
a66_q3a_sandworm
a59_q3_hole
------------------
a60a_q3_xor_roada58_q3_p3_PandG
ex05h1_rank
ex05e3_catapult
ex06e2_shortest
ex06e3_columbia
a64_q3_shortest_start
ex06m1_massrelay
ex06m2_exchange
a61_q2_farthest
-------------
a58_q3_p3a_hacking
a65_q3a_expressway
a66_f1_ev_truck	
a66_q4a_clique
a66_q3b_hex_map_v2