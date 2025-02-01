# AAA
- Larger Restaurant : must choose l and r correctly. add break point `if (cus >= q)`. a special case when q < N must print "0\n";

# AA
- a58_q1_triple : sum of three ในอันที่ sort ไปแล้ว โดยใช้ B-search หาอีกสองตัวที่เหลือ, use ll
- aa_a63_q1b_virus2 : D&C แบบ return ทั้ง bool และ int

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