A, B, C, D = map(int, input().split())
even_r = (D - B) // 2 + (B & 1) * ((D - B) & 1)
odd_r = (D - B) - even_r

ans = 0
ans += even_r * ((C - 1) // 4 - (A - 1) // 4)
ans += even_r * ((C - 2) // 4 - (A - 2) // 4) * 2
ans += even_r * ((C - 3) // 4 - (A - 3) // 4)
ans += odd_r * (C // 4 - A // 4)
ans += odd_r * ((C - 1) // 4 - (A - 1) // 4) * 2
ans += odd_r * ((C - 2) // 4 - (A - 2) // 4)

print(ans)
