#define mul(x, y) (1ll * x * y >= mod ? 1ll * x * y % mod : 1ll * x *y)
#define minus(x, y) (1ll * x - y < 0 ? 1ll * x - y + mod : 1ll * x -y)
#define plus(x, y) (1ll * x + y >= mod ? 1ll * x + y - mod : 1ll * x+ y)
#define ck(x) (x >= mod ? x - mod : x)


void add(int &x, int y) {
	(x += y) >= mod && (x -= mod);
}
void sub(int &x, int y) {
	(x -= y) < 0 && (x += mod);
}

