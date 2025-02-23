# A
- 2 Side Billboard : ใช้ยังไงนะ
- Bigger Billboard : แยกได้สวยมาก
- Pressure Station : เยอะมาก ปวดหัว ปวดตา ;=;
- Arch Match : จิ้ม i = 1 -> N, j = N -> 1
```
dp[i][j] = (a[i] * a[j]) + dp[i + 1][j - 1];
for (int k = i; k < j; k++)
{
    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
}
```

# AA
- distance one : เขียนบิต 0/1 ที่ 1 ต้องห่างกันอย่างน้อย K
- eating futomaki : checking index when you check dp[i][j] 
- ex03e2_mcm : งง คอนเซป
- a60b_​mid_​p3_​divide : หิน N ก้อน แบ่ง K กลุ่ม โดยหินทุกตัวเหมือนๆกัน
  - จำค่าใน dp[i][j] วน i = 1 -> N, j = 1 -> min(N,K)
  - dp[i][1] = 1 เสมอ
  - dp[i][j] มีสองกรณี
    - แยกหินก้อนนั้นออกมา {i-1} {1} ได้ `dp[i-1][j-1]` (ไปแบ่ง i-1 ตัวเป็น j-1 กอง)
    - มี j กองอยู่แล้ว แล้วเราใส่หินก้อนใหม่ไปในหนึ่งในกลุ่มนั้น `j * dp[i-1][j]`
  - Tile : เลือกแลกกระเบื้องบางอัน ให้มีผลรวมพื้้นที่ให้ได้ M ใช้ dp[2][M] กำหนดเป็น INF ก่อน
    - เมื่อรับกระเบื้อง x เข้ามา
    - พิจารณาทุกๆ m ตั้งแต่ m=M -> m=0 มากำหนดพื้นที่ที่เราต้องการ
    - ลองแลกกระเบื้อง ตั้งแต่ k=0 -> k=100 (ค่า M มากสุด ที่ 10000 ยังไงก็ต้องการแลกไม่เกิน 100 แน่ๆ)
      - if(m - k*k < 0) break; แลกพื้นที่มาเยอะเกินไป
      - dp[now][m] = min(dp[now][m], dp[prev][m - (k*k)]+(x-k)*(x-k));
        - การจะได้พื้นที่ m เอามาเทียบว่าใช้อันเดิม(dp[now][m]) หรือเอาแบบที่ไปเปลี่ยนมา  p[prev][m - (k*k)] + (x-k)*(x-k) อันไหนดีหว่ากัน
    - แต่ละรอบก็สลับ now, prev ไปเรื่อยๆ

# AAA
- square : หาสี่เหลี่ยมจตุรัสที่ใหญ่ที่สุด โดยการทำ pf ไปก่อน จากนั้นวนค่า i=R-1, j=C-1 ใหญ่ไปเล็กจะ optimize กว่า
  - จำค่า ans ไว้ก่อนว่า ตอนนี้ชนาดใหญ่สุดๆของเราคือเท่าไหร่
  - ให้ K = min(i,j) ดูว่ากรอบในตำแหน่ง i,j  ใหญ่ได้แค่ไหน
  - for( k = K ; k>ans ; k--)
    - หาก pf ในช่วงกรอบ (i-k, j-k) ถึง (i,k) == k*k แปลว่าทุกช่องเป็น 1 หมด ->  ans = k; break;
    - ถ้าไม่ใช้ ให้ลดขนาด k ลง อาจจะมีสี่เหลี่ยมในกรอบเล็กๆนี้ได้
- two one apart : ลองแค่ไปแยก state อีกรอบพอ เหน่ย
- Barcode : นีรทำแยก state 3 dim ซึ่งผ่านนะ, แต่ลองดู sol เฉลย ที่เก็บใน dp 2 dimension
```
for(int l=1;l<=m;++l) a[l][0]=1;

for(int i=1;i<n;++i)
    for(int j=0;j<k;++j)
        for(int l=1;l<=m;++l) a[i+l][j+1]+=a[i][j];
printf("%d",a[n][k]);
```
- Buffet line : คือโจทย์ยาวทำชีมาก แต่จริงๆแล้วค่า m มัน static ไม่แปรตามลำดับการตักและเวลา ความอร่อยของอาหารเลยเหมือนลดลงไป d[i] - m เลย
  - ทำ prefix sum ของอาหารในแถวนี้ไปเรื่อยๆ
  - แล้วพอหมอเริ่มตักอาหารที่ st แล้วต้องการความอร่อย >= w ก็แค่ไปหา index ที่มีค่า pf[ed] >= w + pf[st-1] (lowerbound)

# Beware
- size_t พอลบแล้วมันไม่เก็บค่าที่เป็น บวกลบ ระวังตอนเอามาเช็คค่าแบบ if (i - c[j] < 0)
- Coin Change ใช้ DP 1 มิติพอ ย้อนค่าเลขเอา
- Reverse Knapsack Items : แต่ละบรรทัดคือ item -> เช็คบรรทัดนั้นด้วยค่า weight ของ item

# Code
- Longest Increasing Subsequence
```
for (int i = 1; i <= N; i++)
  dp[i] = 1;
  for (int j = 1; j < i; j++)
    if (a[i] > a[j])
      dp[i] = max(dp[i], dp[j] + 1);
  ans = max(ans, dp[i]);
```
- Longest Common Subsequence
```
// normal case, get last maximum longest {s1 - 1, s1} or {s1, s2 -1}
dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
// if character match, see {s1 - 1, s2 - 1}
if (s1[i] == s2[j])
  dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
```