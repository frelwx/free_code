import math
Pt = 16000
Gt = pow(10, 31 / 10)
Gr = Gt
lambda_ = 0.03
sigma = 1
k = 1.380649 * 1e-23
T0 = 273
Bn = 2e7
Fn = pow(10, 10 / 10)
D0 = pow(10, 14 / 10)
tmp = (Pt * Gt * Gr * lambda_ * lambda_ * sigma) / (pow(4 * math.pi, 3) * k * T0 * Bn * Fn * D0)
ans = pow(tmp, 1 / 4)
print(ans)