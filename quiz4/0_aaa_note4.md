# Mistake

- เวลาลูปใน pq อย่าลืมเช็ค !pq.empty()
- เรียง distance ก่อน state
- เวลา shift bit ดูด้วยว่าต้องใช้ (1 << (i-1)) ไหม
- function อย่าลืม return ด้วย ! ไม่งั้น xxxxxx

# Greedy

- Team Work : reward คืออยากให้งานเสร็จไว คนทำงานเท่ากัน ให้แจกงานที่ระยะสั้นไป N คน แล้วถ้าเหลือ ค่อยแจกซ้อน (อ่านโค้ดน่าจะเกตกว่า)
- Interval Selection : อยากเลือกงานที่มี [start, finish] ให้ได้เยอะสุด ใช้ pq เรียงตาม finish แล้ววนลูป

```
while (!pq.empty())
{
    ans++;
    t = pq.top().w; pq.pop();
    while (!pq.empty() && pq.top().s < t) pq.pop();
}
```

- Buffet : ติดไฟที่กว้าง w-x ถึง w+x ถ้ามีอาหารที่ตำแหน่ง y ให้ติดแล้วครอบคลุมไปจบ y+2\*W

# Niche

- Fractional Knapsack : เวลาใช้ double ให้เอาตัวแปรทุกอย่างเป็น double เผื่อ

```
priority_queue<tuple<double, double, double>> aw;
scanf("%lf", &x);
printf("%.4lf", ans);
```

- N Queen : อ่านไฟล์ nqueen ดู หลักๆคือมี col และ col_of_row ไล่ผ่านฟังก์ชั่น f(row)

- 3sort : number of minimum swap number till array is sorted
  - นับจำนวน 1,2,3 ใน m
  - place = m[1] // ที่ที่ wrong 1 จะเจอได้
  - วนค่า i=0, i < m[1] : หากเจอ 2,3 ให้ ct++, แล้ววนลูปหา place ใหม่ที่ `while(place < N && a[place]!= 1) place++`
  - วนค่า i=m[1] , i < m[1]+m[2], หากเจอ 3 ให้ ct++
- Lightspeed Salesman : (graph?) remember prefix clockwise
  - path(u,v) ; `u < v` -> `min(pf[v]-pf[u], sum - (pf[v]-pf[u]))`
  - dis(int st, int ed, int u, int v) ; from all company[i], company[i+1]
    ```
    ll ans = path(st, ed);                     // basecase
    ans = min(ans, path(st, u) + path(v, ed)); // portal u -> v
    ans = min(ans, path(st, v) + path(u, ed)); // portal v -> u
    ```
- travelling_tourist
  - เก็บ state แค่เมืองที่ต้องการไปเที่ยว (เมือง K) แบบ bitmask
  - ทำ priority_queue เป็น dist และ state จะไปเมืองไหนต่อก็ floyde-marshell
- Journey
  - (80%) tuple lightweight กว่า struct, เรียง distance ก่อน state
  - (90%) set ค่าใน dp[u][i] ก่อนจะยัดเข้าใน pq ด้วย
- Fracmental Knapsack : ทำ เลือก/ไม่เลือก ที่มี prunning โดยการ predict ค่าที่ดีที่สุดที่เราจะเลือกเข้ากระเป๋าได้แบบทศนิยม
  - ยอมเสีย O(N) เพื่อตัด O(2^N)
  - ตอนเช็ค prunning จะ return ค่าของ double เพิ่ม bound ก็ดี `if (price + pd + 1 <= ans) return;` (แต่เจอไม่บ่อย)
  - นีรอย่าเรียก predict(id+1) ทั้งที่มันเลือก id ตัวเองได้สิ แง ;-;
- path sum : คำนวน best แค่เฉพาะ node ที่ยังไม่ได้ไปก็พอ
  - ยอมเสีย N เพื่อตัด N^2 เยอะๆ !

```
int best = 0;
for (size_t i = 0; i < N; i++)
{
    if (!vis[i])
        best += b[i];
}
if (dist > target || dist + best < target)
    return false;
```

- Subset Sum

# list of chore

: it's a list
: wrongggg. it's a list, a list of chore

state space search ----
da67_f_travelling_tourist +++
a57_f4_journey
a64_q4_path_sum
a65_q4_collector
ex07m2_15puzzle (niche ไป ไม่ทำ)
ex07e3_coloring
a64_q4_closest_subset
da66_f1_buffet_flight
ex07e2_iss
ex07e1_nqueen
ex07m1_knapsack
a66_q4a_clique
a66_q3b_hex_map_v2

greedy ---
ex04e2_fknapsack
ex04e3_teamwork
a60b_mid_p1_buffet
ex04e1_interval
a58_m4_supply
a57_f3_drainage
ex04m1_sort
ex04m2_salesman +++
ex04h1_montblanc
a65_q4_tower_defense_2
da66_f1_sea_bridge (NP)
