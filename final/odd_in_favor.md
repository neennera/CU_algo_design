# PRUNNING

- pruning เอาค่าเพ้อมากๆ ให้สูงได้ เช่น best happy ที่ได้จากการออก node
- path sum : คำนวน best แค่เฉพาะ node ที่ยังไม่ได้ไปก็พอ
- ยอมเสีย O(N) เพื่อตัด O(2^N)

```
double vv = (ww == a[id].w ? a[id].v : (a[id].ratio * ww));
```

- ทำ state

```
if (state == end_state && ept == 2 * N) // มีเงื่อนไขอื่น นอกจาก 0/1
vis[ept][state] = 1;

if ((new_state >> v) & 1)
	new_state = (new_state) ^ ((1 << v) + (1 << ept)); // กลับบิตแค่บางจุด แค่ตอนอ่านเป็น 0<->1

if (d + pre_cost <= dp[(1 << N) - 1][N])

for (int i = 0; i < N; i++)  state += (1 << i);
```

# PQ

- bool opreator < (const DATA &o2) const
- tuple is more light weight
- เรียง distance ก่อน state distance is more value than state !

```
priority_queue<tuple<int, int, int, int>> pq;
int last = get<0>(pq.top());
```

- ระวังการ access pq ที่เรา pq.pop() ไปแล้ว

# Mistake

- เวลาลูปใน pq อย่าลืมเช็ค !pq.empty()
- เวลา shift bit ดูด้วยว่าต้องใช้ (1 << (i-1)) ไหม
- function อย่าลืม return ด้วย ! ไม่งั้น xxxxxx
- ระวัง index โดยเฉพาะสลับ (x,y) หรือการใช้ (i,j) คู่ loop for i
- ระวังเช็ค `ny>N, ny<M`
- จะหา cycle ใน undirected ระวังวนไปเจอ pa
- vector<vector<int>> ดีกว่า
- แยก array ดีกว่าทำ vector<pair>
- อย่าลืม set pa[i]
- in the middle : ใช้ stack(DFS) ไม่ผ่าน แต่ใช้ queue(BFS) ผ่าน => ใช้ queue มันก้าวสั้นกว่า
- unsigned long long กับ 2^30
- เวลาค่าติดลบได้ อย่าใช้ INT_MIN -> 10^6 แทน
- อย่าลืมรับค่าและเซตค่าเริ่มต้น
- ถ้ารันรับค่าไม่ได้ ให้เช็คว่า vector ได้ resize ยัง
- ระวัง `dist[v] <= w + ww`
- floynd-warshell
  - อย่าลืม set a[i][i] = 0 ตอนแรก
  - เรียง k, i, j เท่านั้น!!
  - เช็ค neg ว่าพอทำไปแล้ว a[i][i] < 0
- Sandworm : พังกรณีที่วาร์ปลงไปเจอหนอนบนช่องที่มีพายุ ต้องดักไว้ด้วย

# Problems

- Exchange : ทำ floynd-warshell O(N^3), ทำ break หาก profit โผล่มาก็ได้
  ```
  A[i][j] = max(A[i][j], A[i][k] * A[k][j]);
  if (i == j) profit |= (A[i][j] > 1);
  ```
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
- Clique
  - ทีมที่ทุกคนต้องเป็นเพื่อนกัน ปัญหาเลือก/ไม่เลือก
  - ทำการตัดจบ state search 0/1 โดยว่าถ้า now + quicksum ที่เหลือด้านหลังมันรวมได้ไม่มากกว่า ans -> อันนี้ไม่ใช่คำตอบแน่ๆ

```
    if (ct + qs[id] <= ans)
        return;
    bool ck = 1;
    for (auto x : use){ if (!a[id][x]) ck = 0; }
    if (ck)
    {
        use.push_back(id);
        f(id + 1, ct + b[id]);
        use.pop_back();
    }
    f(id + 1, ct);

```

- SCC
  - set vis = 0
  - DFS1 : ให้ vis=1, ไปหาลูก v , ยัดเข้า order
  - set vis = 0
  - DFS2 : ใช้ reverse path, order หลังมาหน้า, ทำ global component++ หรือ component.push_back(u)
  - ตอนจบ clear component, ย้ายค่าไปใน vector (กรณีเอาตัว) หรือ ans = max(ans, componnent) กรณีเอาจำนวน
- Pacman and Ghost
  - กำหนดให้ตอนแรกเป็น -1 ถ้ายังมาไม่ถึง -2 ถ้าเข้าไม่ได้
  - flood fill จำเวลาที่มาถึงช่องได้ไวสุด
  - แพ็คแมนจะหนีได้หากมีช่องนึงที่ ( ctPac[i][j] >= 0 ) && ( ctGhost[i][j] < 0 )
  - คือ แพ็คแมนถึงละ ผียังไม่ถึง ดังนั้น สามาถจู๊คได้

```

```
