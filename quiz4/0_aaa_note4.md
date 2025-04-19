# Mistake
- เวลาลูปใน pq อย่าลืมเช็ค !pq.empty()

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
- Buffet : ติดไฟที่กว้าง w-x ถึง w+x ถ้ามีอาหารที่ตำแหน่ง y ให้ติดแล้วครอบคลุมไปจบ y+2*W

# Niche
- Fractional Knapsack : เวลาใช้ double ให้เอาตัวแปรทุกอย่างเป็น double เผื่อ
```
priority_queue<tuple<double, double, double>> aw;
scanf("%lf", &x);
printf("%.4lf", ans);
```
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

# list of chore
: it's a list
: wrongggg. it's a list, a list of chore


state space search ----
a57_f4_journey
da67_f_travelling_tourist
a64_q4_path_sum
a65_q4_collector
ex07m2_15puzzle
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
ex04m2_salesman ***
a65_q4_tower_defense_2
ex04h1_montblanc
da66_f1_sea_bridge