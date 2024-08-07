struct Mod
{
    long long m, p;
    void init(int pp) { m = ((__int128)1 << 64) / pp; p = pp; }
    long long operator ()(long long x){
        return x - ((__int128(x) * m) >> 64) * p;
    }
} mod;