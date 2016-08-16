string itob(int x)
{
	string res;
	while (x)
		res = char(x % 2 + '0') + res,
		x /= 2;
	return res;
}

int btoi(string bit)
{
	int res = 0;
	for (int i = 0; i < bit.size(); ++i)
		res = res * 2 + int(bit[i] - '0');
	return res;
}

void activate_bit(int &x, int p)
{
	x |= (1 << (p - 1));
}

void toggle_bit(int &x, int p)
{
	x ^= (1 << (p - 1));
}

void deactivate_bit(int &x, int p)
{
	activate_bit(x, p);
	toggle_bit(x, p);	
}

bool get_bit(int &x, int p)
{
	return x & (1 << (p - 1));
}