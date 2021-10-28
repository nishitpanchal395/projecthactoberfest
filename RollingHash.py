class RollingHash():
    def __init__(self, s):
        self.length = len(s)
        self.base = 1009
        # self.mod = 2147483647 # M31
        # self.mod = 67280421310721 # 2^64 + 1 // 274177
        self.mod = 2305843009213693951 # M61
        self.hash = [0] * (self.length + 1)
        self.pow = [1] * (self.length + 1)

        for i in range(self.length):
            self.hash[i+1] = (self.hash[i] + ord(s[i])) * self.base % self.mod
            self.pow[i+1] = self.pow[i] * self.base % self.mod

    # Get rolling hash of s[l:r)
    def get(self, l, r):
        t = self.hash[r] - self.hash[l] * self.pow[r-l] % self.mod
        return t % self.mod

if __name__ == "__main__":
    a = "homuhomu"
    RH = RollingHash(a)
    print(RH.get(0,4))

    a = "poehomug"
    RH = RollingHash(a)
    print(RH.get(3,7))