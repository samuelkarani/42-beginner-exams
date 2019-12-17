#include <unistd.h>

int print_num(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
			return write(1, "-2147483648", 10);
		write(1, "-", 1);
		return print_num(n * -1);
	}
	if (n >= 10)
		print_num(n / 10);
	char c = n % 10 + '0';
	return write(1, &c, 1);
}

int calc(int a, int b, char c)
{
	if (c == '+')
		return a + b;
	if (c == '-')
		return a - b;
	if (c == '*')
		return a * b;
	if (c == '/')
		return a / b;
	return a % b;
}

// FP Exception i.e. div by 0
int main(int ac, char **av)
{
	char ops[] = {'+', '-', '*', '/', '%'};
	int err = 0;
	if (ac != 2)
		err = 1;
	if (!err)
	{
		char *s = av[1];
		int i = 0, nops = 0, nums = 0;
		while (s[i])
		{
			int j = i;
			while (s[i] == ' ')
				i++;
			int k = i;
			while (s[i] >= '0' && s[i] <= '9')
				i++;
			if (i > k)
				nums++;
			if (s[i] == ops[0] || s[i] == ops[1] || s[i] == ops[2] || s[i] == ops[3] || s[i] == ops[4])
			{
				i++;
				nops++;
			}
			if (i == j)
				break;
		}
		if (s[i] || nums - 1 != nops)
			err = 1;
		if (!err)
		{
			int i = 0, idx = 0;
			int arr[nums];
			while (s[i])
			{
				while (s[i] == ' ')
					i++;
				int sum = 0;
				int j = i;
				while (s[i] >= '0' && s[i] <= '9')
				{
					sum *= 10;
					sum += s[i] - '0';
					i++;
				}
				if (i > j)
					arr[idx++] = sum;
				if (s[i] == ops[0] || s[i] == ops[1] || s[i] == ops[2] || s[i] == ops[3] || s[i] == ops[4])
				{
					arr[idx - 2] = calc(arr[idx - 2], arr[idx - 1], s[i]);
					idx--;
					i++;
				}
			}
			print_num(arr[0]);
		}
	}
	if (err)
		write(1, "Error", 5);
	write(1, "\n", 1);
}
