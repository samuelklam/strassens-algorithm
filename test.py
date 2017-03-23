# 233 pads to 234 (1 pad)
# 234 - 117
# 117 pads to 118 (4 pads)
# 118 -> 59, uses conventional

def done(n):
  while n > 64:
    if n % 2 != 0:
      return False
    n /= 2
    if n <= 64:
      return True
  return False

n = 233
pad = 0
while (True):
  if done(n+pad):
    break
  else:
    pad += 1
print pad
