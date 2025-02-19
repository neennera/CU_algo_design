# AAA
- Larger Restaurant : must choose l and r correctly. add break point `if (cus >= q)`. a special case when q < N must print "0\n";
- a61_q1_thanos : เก็บ avenger เป็น array ยาวๆ แล้วค่อยหาจำนวนโดยการ lower_bound (ถ้าเป็น array ใช้ b-search)  ที่เหลือแค่แบ่งช่วง และอ่านโจทย์ดีๆ เราชอบ return min(A, B*m) แต่จริงๆมันมีเงื่อนไข
- a60b_q2_pareto : อย่าลืม sort จุด, ถ้าวนเช็ค + ใน break จะได้ 90 ติด T, sol = เราถือว่าเราเรียง y แล้ว พอทำการ divide ไปที่แต่ละอันจะโยน min_x ไปด้วย
  - l==r :  หาก p[l].second > minx ก็ return  {1, p[l].second} (y ตัวต่อไปมีแต่ >= เลยเอา x มาเทียบ) แต่ถ้าไม่ใช่ จะใช้  {0, minx} เป็น minx ตัวเดิม
  - auto r1 = pareto(mid + 1, r, minx);
  - auto r2 = pareto(l, mid, r1.second);
  - คือไปหาตัวที่ y น้อยกว่าก่อน แล้วเอา minx ของตัวก่อนหน้ามาใช้
  - สุดท้าย return {r1.first + r2.first, r2.second} เป็นจำนวนตัว และ minx ล่าสุด
- a64_q2_two_mcs : let index 0 is an answer that only use 1 MCS, index 1 is an answer that has 2 MCS
  - ข้อนี้ใช้ INT_MIN, -1e9 ผ่าน แต่ LLONG_MIN ไม่ผ่าน งอง
```
cur[1] = max(cur[1] + x, ans[0] + x); // cur 1 is from cur_now, or MCS + x
ans[1] = max(ans[1], cur[1]);
cur[0] = max(cur[0] + x, x); // use like normal cur
ans[0] = max(ans[0], cur[0]);
```
- a65_q1_mt_matrix : ถ้าค่อยๆเจาะ index แล้วกำหนด flag neg, T มันจะไม่ได้ เพราะตอน T ค่ามันไม่ได้หักล้างกัน ให้ใช้การตัด metirx เอา โดยสมมุติว่าเราจะไปที่ top-right ก็ต้องให้ j-mid แล้วไปเจาะดู metrix คัวนั้น, ส่วนการ Transport ก็แค่ทำการสลับ i <-> j เช่น get_mt(j-mid, i-mid), หากมี neg ก็ใช้  -get_mt(i-mid,j) 
- a59_midp4_mcsw : ใช้ dequq มาทำ sliding window ที่มีการกำหนด width (ต้อง pop front, pop back ออก)
```
q.push_back({-1, 0}); // basecase
>> loop
while (!q.empty() && i - q.front().first > W)
{
    q.pop_front();
}
maxx = max(maxx, cur - q.front().second);
while (!q.empty() && q.back().second >= cur)
{
    q.pop_back();
}
q.push_back({i, cur});
```
- a64_q1_lawn_mowing : B-search แต่ค่าที่เอามาคิดช่วงคือ mid และ a
  - ใช้ l<=r ; l = mid+1, r=mid-1
```
while (l <= r)
{
    ll mid = (l + r) >> 1;
    ll p = (pf[mid] - pf[a - 1]) + ((mid - a + 1) * K);
    if (p <= b)
    {
        ans = max(ans, pf[mid] - pf[a - 1]);
        l = mid + 1;
    }
    else
    {
        r = mid - 1;
    }
}
```


# AA
- a58_q1_triple : sum of three ในอันที่ sort ไปแล้ว โดยใช้ B-search หาอีกสองตัวที่เหลือ, use ll
- aa_a63_q1b_virus2 : D&C แบบ return ทั้ง bool และ int
- a66_q1a_day_cover : ถ้าคิดไม่ออกแล้วเลขมันน้อยๆ brute force ไปที่ลองใช้แต่ละคนเลย แล้วมา optimize กับการเช็ค count, จำนวนนักเรียน แทน, เก็บ last เป็นนักเรียนที่เริ่มเลือกด้วย
- a57_m5_mcs2 : จำทั้ง minn, maxx แล้ว ตอบ max(maxx, (sum == minn ? maxx : sum - minn))
- (เดี๋ยวกลับมาทำแบบตังเม)a66_q1a_day_cover : ไม่รู้ว่าทำไม แต่ใช้ stu_ct เป็น global แล้วทำการ stu_ct++ มันติด T, การที่วนลูปเพื่อเก็บวันว่าได้กี่วันแล้ว ก็ติด T แต่พอใช้การ mark ไปเลย ค่อยเช็คตอนท้าย ดันไม่ติด
- a66_q2a_insertion_count : โจทย์เขียนไม่รู้เรื่อง... คือเขาให้หาว่าที่ช่องที่บรรจุตำแหน่ง k จะต้องมีการถูกขยับไปแทนค่าในคำสั่ง A[i-1] = A[i] กี่ครั้ง ซึ่งคำตอบนี้จะเป็นจำนวนของช่องก่อนหน้า A[i] ที่มีค่า A[id] > A[i] เพราะถ้าช่องถูกพิจารณา เราต้องมาขยับตัวนี้


# A
- ex01e4_mod_expo : จัดรูป mode สวย
- virus : เช็ค reverse string
- a66_q1b_triforce : ตรง index ใช้ `int mid_h = (i1 + i2) / 2, int mid_w = (j1 + j2) / 2` และระวังกรณี ที่ type เป็น 0 อันสามอันบนซ้าย
- da66_m1_line_paint : ทำ sweep line จำตอนที่เริ่มขึ้น sweep และ ตอนลง
- a60_q1_matmod : ใช้ tuple<int, int, int, int> เวลาเอาออก ใช้
```
int a1, b1, c1, d1;
tie(a1, b1, c1, d1) = a;
```
- a57_m4_gaa : แค่ซอย recursive แต่ระวัง index ที่เริ่มที่ 1

# Tips
- หากจะยกกำลังสองเยอะๆ ใช้ (1LL << n)
- vector<vector<ll>> ansMe(4) มาแก้ ansMe[0] = {A, B, C, D} ทีหลังได้
- boolean ถ้ากำหนดเป็น 0 แล้วอยากใช้ not ให้ใช้  !b
- substr(start, stop) ex: s1.substr(0, mid), s2.substr(mid, length)




# Extra
Maximum Subarray Sum
```
cur = max(x, cur + x);
maxx = max(maxx, cur);
```