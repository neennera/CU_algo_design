# AAA
- Larger Restaurant : must choose l and r correctly. add break point `if (cus >= q)`. a special case when q < N must print "0\n";
- a61_q1_thanos : เก็บ avenger เป็น array ยาวๆ แล้วค่อยหาจำนวนโดยการ lower_bound (ถ้าเป็น array ใช้ b-search)  ที่เหลือแค่แบ่งช่วง และอ่านโจทย์ดีๆ เราชอบ return min(A, B*m) แต่จริงๆมันมีเงื่อนไข
- a60b_q2_pareto : อย่าลืม sort จุด, ถ้าวนเช็ค + ใน break จะได้ 90 ติด T, sol = เราถือว่าเราเรียง y แล้ว พอทำการ divide ไปที่แต่ละอันจะโยน min_x ไปด้วย
  - l==r :  หาก p[l].second > minx ก็ return  {1, p[l].second} (y ตัวต่อไปมีแต่ >= เลยเอา x มาเทียบ) แต่ถ้าไม่ใช่ จะใช้  {0, minx} เป็น minx ตัวเดิม
  - auto r1 = pareto(mid + 1, r, minx);
  - auto r2 = pareto(l, mid, r1.second);
  - คือไปหาตัวที่ y น้อยกว่าก่อน แล้วเอา minx ของตัวก่อนหน้ามาใช้
  - สุดท้าย return {r1.first + r2.first, r2.second} เป็นจำนวนตัว และ minx ล่าสุด


# AA
- a58_q1_triple : sum of three ในอันที่ sort ไปแล้ว โดยใช้ B-search หาอีกสองตัวที่เหลือ, use ll
- aa_a63_q1b_virus2 : D&C แบบ return ทั้ง bool และ int
- a66_q1a_day_cover : ถ้าคิดไม่ออกแล้วเลขมันน้อยๆ brute force ไปที่ลองใช้แต่ละคนเลย แล้วมา optimize กับการเช็ค count, จำนวนนักเรียน แทน, เก็บ last เป็นนักเรียนที่เริ่มเลือกด้วย


# A
- ex01e4_mod_expo : จัดรูป mode สวย
- virus : เช็ค reverse string
- a66_q1b_triforce : ตรง index ใช้ `int mid_h = (i1 + i2) / 2, int mid_w = (j1 + j2) / 2` และระวังกรณี ที่ type เป็น 0 อันสามอันบนซ้าย





# Extra
Maximum Subarray Sum
```
cur = max(x, cur + x);
maxx = max(maxx, cur);
```